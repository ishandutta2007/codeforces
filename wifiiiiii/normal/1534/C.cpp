#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 500005;
const int mod = 1e9+7;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        for(int i=1;i<=n;++i) par[i]=i;
        for(int i=0;i<n;++i) {
            par[find(a[i])]=find(b[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;++i) cnt+=find(i)==i;
        cout<<fpow(2,cnt)<<'\n';
    }
}