#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n,cnt=1;
ll sum[N],t,a[N],BIT[10*N];
set<ll> s;
void init_bit(){for(int i=0;i<10*N;i++)BIT[i]=0;}
void Add(int x){for(;x>0;x-=x&-x)BIT[x]++;}
ll Get(int x){ll res=0;for(;x<10*N;x+=x&-x)res+=BIT[x];return res;}
int main(){
    cin>>n>>t;
    init_bit();sum[0]=0;
    for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i],s.insert(sum[i]),s.insert(sum[i]-t);}
    map<ll,int> hsh;
    for(ll c:s)hsh[c]=cnt++;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=Get(hsh[sum[i]-t]+1);
        Add(hsh[sum[i]]);
        if(sum[i]<t)ans++;
    }
    cout<<ans;
    return 0;
}