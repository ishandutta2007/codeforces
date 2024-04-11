#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
int C[maxn],n,a[maxn],p[maxn];
long long ans=0,dist=0,m=0;
int ck=0;
set<int> s;
int lowbit(int u){
    return u&(-u);
}

void update(int u){
    for (int i=u;i<=n;i+=lowbit(i)) C[i]+=1;
}

int query(int u){
    int ans=0;
    for (int i=u;i>0;i-=lowbit(i)) ans+=C[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        p[a[i]]=i;
    }
    ck=-2;
    for (int i=1;i<=n;++i){
        dist+=fabs(p[i]-m);
        if (p[i]>m) ck++;
        else ck--;
        s.insert(p[i]);
        if (i%2&&ck){
            auto iter=s.find(m);
            if (ck>0) iter++;
            else iter--;
            int ne=*iter;
            dist-=fabs(ne-m);
            m=ne;
            ck=0;
        }
        dist-=i/2;
        update(p[i]);
        ans+=query(n)-query(p[i]);
        printf("%lld\n",dist+ans);
    }
    return 0;
}