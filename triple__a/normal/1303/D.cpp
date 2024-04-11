#include<bits/stdc++.h>
using namespace std;

const int maxn=37;
long long n,m,f[maxn],sum[maxn],t;

int calc(long long u){
    for (int i=0;i<60;++i){
        if (u>>i&1) return i;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    cin>>n>>m;
    int ret=0;
    for (int i=1;i<=m;++i){
        long long u;
        cin>>u;
        f[calc(u)]++;
    }
    for (int i=0;i<32;++i){
        sum[i]=(1ll<<i)*f[i];
    }
    for (int i=1;i<32;++i) sum[i]+=sum[i-1];
    if (sum[31]<n){
        cout<<"-1"<<endl;
        goto cont;
    }
    for (int i=31;i>-1;--i){
        n=n%(1ll<<i);
        if (i>0&&sum[i-1]<n) ret++;
    }
    cout<<ret<<endl;
    cont:;
    }
    return 0;
}