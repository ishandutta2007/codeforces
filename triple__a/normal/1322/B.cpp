#include<bits/stdc++.h>

using namespace std;

const int maxn=4000007;
int n,m,a[maxn],b[maxn];
vector<int> C;

int lowbit(int u){
    return u&(-u);
}

void update(int u,int w){
    for (int i=u;i<=n;i+=lowbit(i)){
        C[i]+=w;
    }
}

int query(int u){
    int ans=0;
    for (int i=u;i>0;i-=lowbit(i)){
        ans+=C[i];
    }
    return ans;
}

mt19937 rng(time(NULL));
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>a[i];
    }
    int ret=0;
    for (int i=24;i>-1;--i){
        for (int j=1;j<=m;++j){
            b[j]=a[j]&((1<<i+1)-1);
        }
        sort(b+1,b+m+1);
        C.clear();
        n=4*(1<<i)+7;
        C.resize(n,0);
        int sum=0;
        for (int j=1;j<=m;++j){
            if (b[j]>>i&1){
                sum+=query((1<<i+1)-b[j])+query(1<<i+2)-query((1<<i+1)+(1<<i)-b[j]);

                sum&=1;
            }
            else{
                sum+=query((1<<i+1)-b[j])-query((1<<i)-b[j])+query(1<<i+2)-query((1<<i+1)+(1<<i)-b[j]);
                sum&=1;
            }
            update(b[j]+1,1);
        }
        if (sum&1) ret+=(1<<i);
    }
    cout<<ret<<endl;

    return 0;
}