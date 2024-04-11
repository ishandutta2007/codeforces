#include<bits/stdc++.h>
#define S second
#define int long long
using namespace std;


const int maxn=1000007;
int n,k;
int a[maxn];
int calc(int n,int k){
    if (n<k) return 100000000;
    int w=n/k, a=n%k, b=k-a;
    return a*(w+1)*(w+1)+b*w*w;
}

int diff(int n,int k){
    return calc(n,k)-calc(n,k+1);
}
set<pair<int,int>> s;
int flr[maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    assert(n<=100000);
    cin>>n>>k;
    for (int i=0;i<n;++i){
        cin>>a[i];
        s.insert({-diff(a[i],1),i});
        flr[i]=1;
    }    
    k-=n;
    while (k--){
        auto x=*s.begin();
        s.erase(x);
        s.insert({-diff(a[x.S],++flr[x.S]),x.S});
    }
    int ans=0;
    for (int i=0;i<n;++i) ans+=calc(a[i],flr[i]);
    cout<<ans;
    return 0;
}