#define ll long long
#define lld long double
#define cn(n)  ll n;cin >> n;
#define tes(t) ll t;cin>>t;while(t--) 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define al(v) v.begin(), v.end()
#define oset(X) tree<X, null_type, less<X>, rb_tree_tag, tree_order_statistics_node_update>
#define roset(X) tree<X, null_type, greater<X>, rb_tree_tag, tree_order_statistics_node_update>
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const ll MOD2 = 998244353;
const long double PI = 3.141592653589793;
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
ll power(ll x, ll y, ll p){ll res = 1;x %= p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
ll po(ll base, ll powerRaised){if (powerRaised != 0)return (base * po(base, powerRaised - 1));else return 1;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif //*
	tes(t)
  {
    ll p,f;
    ll cnts,cntw,s,w;
    cin>>p>>f;
    cin>>cnts>>cntw>>s>>w;
    if(s>w)
    {
      swap(s,w);
      swap(cnts,cntw);
    }
    ll res=0;
    for(int i=0;i<=cnts;i++)
    {
      ll c1=cnts,c2=cntw;
      ll x;
      if(p<i*s)
      x=0;
      else x=i;
      ll y=min((p-i*s)/w,cntw);
      c1-=x;
      c2-=y;
      res=max(res,x+y+min(f/s,c1)+min((f-min(f/s,c1)*s)/w,c2));
      
    }
    cout<<res<<endl;
  }
	
	
}