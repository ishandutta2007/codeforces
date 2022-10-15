#include<bits/stdc++.h>
using namespace std;

const int maxn=1027;
int n,k,b;
bool vis[maxn];
bool query(int u){
    cout<<"? "<<u<<endl;
    char c;
    cin>>c;
    return c=='Y';
}

void block(int u){
    for (int i=(u-1)*b+1;i<=u*b;++i){
        if (query(i)) vis[i]=1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    b=(k+1)/2;
    for (int i=1;i<n/b;++i){
        for (int k=1;k<=i;++k){
            if (k+i>n/b) continue; 
            for (int j=k;j<=n/b;j+=i){
                block(j);
            }
            cout<<"R"<<endl;
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) ans+=1-vis[i];
    cout<<"! "<<ans<<endl;
    return 0;
}