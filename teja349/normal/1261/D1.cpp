//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll

ll inv[300003],mult[300003],invmult[300003];
ll gcd(ll a,ll b){
  while(b!=0){
    
    a=a%b;
    swap(a,b);
  }
  return a;
}

ll extend_gcd(ll a,ll b,ll &x,ll &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  ll x1,y1;
  ll ans =extend_gcd(b,a%b,x1,y1);
  x=y1;
  y=x1-(a/b)*y1;

  return ans;
}

ll combination(ll n,ll r){
  if(r==0)
    return 1;
  if(n<r)
    return 0;
  ll ans=1;
  ans*=mult[n];
  ans%=mod;
  ans*=invmult[r];
  ans%=mod;
  ans*=invmult[n-r];
  ans%=mod;
  return ans;
}

ll initcombi(){
  int i;
  f(i,1,300001){
    ll x,y;
    ll val=extend_gcd(mod,i,x,y);
    if(y>0)
      inv[i]=y%mod;
    else{
        inv[i]=(y+mod)%mod;
    }
  }
  mult[0]=1;
  f(i,1,300001){
    mult[i]=mult[i-1]*i;
    mult[i]%=mod;
  }
  invmult[0]=1;
  f(i,1,300001){
    invmult[i]=invmult[i-1]*inv[i];
    invmult[i]%=mod;
  }
  return 0;
}


// do initcombi();
int ans[312345];
int pp[312345],two[312345];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    initcombi();
    int n,k;
    cin>>n>>k;
    int i;
    rep(i,n){
      cin>>ans[i];
    }
    ans[n]=ans[0];
    int boo=1,left=n;
    rep(i,n){
      if(ans[i]==ans[i+1]){
        boo*=k;
        boo%=mod;
        left--;
      }
    }
    int ways=0; 
    pp[0]=1;
    two[0]=1;
    f(i,1,212345){
      pp[i]=pp[i-1]*(k-2);
      pp[i]%=mod;
      two[i]=two[i-1]*2;
      two[i]%=mod;
    }
    int inv2=inv[2];
    int gg,who,what;
    rep(i,left){
      gg=left-i;
      who = combination(left,i);
      who*=pp[i];
      who%=mod;
      if(gg%2){
        who*=two[gg-1];
        who%=mod;
      }
      else{
        what=two[gg]-combination(gg,gg/2);
        if(what<0){
          what+=mod;
        }
        what*=inv2;
        what%=mod;
        who*=what;
        who%=mod;
      }
      ways+=who;

    }

    ways%=mod;
    ways*=boo;
    ways%=mod;
    cout<<ways<<endl;
    return 0;   
}