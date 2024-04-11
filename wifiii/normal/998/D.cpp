#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

vector<pair<int,int>> vec[100];
ll solve(vector<pair<int,int>> a) {
    ll ret = 0;
    vector<int> aa;
    for(auto p : a) {
        aa.push_back(p.first);
        aa.push_back(p.second);
    }
    sort(aa.begin(), aa.end());
    aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
    auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
    vector<int> c(aa.size());
    for(auto p : a) c[f(p.first)]++, c[f(p.second)]--;
    int sum = 0;
    for(int i=0;i<c.size();++i) {
        sum += c[i];
        if(sum) ret += aa[i+1] - aa[i];
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    set<ll> s;
    ll ans=0;
    unordered_map<ll,int> mp;
    for(ll a2=0;a2<9;++a2) {
        for(ll a3=0;a3<49;++a3) {
            if(a2+a3 > n) break;
            ll tmp = a2*4+a3*9, a4 = n-a2-a3;
            ll l = tmp / 49, r = l + a4;
            vec[tmp%49].push_back({l, r + 1});
        }
    }
    for(int i=0;i<49;++i) {
        if(vec[i].empty()) continue;
        ans += solve(vec[i]);
    }
    cout << ans << endl;
}