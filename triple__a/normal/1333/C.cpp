#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=200007;
int a[maxn],n,b[maxn],c[maxn],res;
map<int,int> ret;
signed main(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i],b[i]=b[i-1]+a[i];
    ret.insert({0,0});
    for (int i=1;i<=n;++i){
        if (ret.find(b[i])!=ret.end()){
            c[i]=ret[b[i]];
        }
        else{
            c[i]=-1;
        }
        ret[b[i]]=i;
    }
    int mx=-1;
    for (int i=1;i<=n;++i){
        mx=max(mx,c[i]);
        res+=i-mx-1;
    }
    cout<<res<<endl;
    return 0;
}