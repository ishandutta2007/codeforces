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

int a[2123][2123];
int dp[2123][2123];
int visit[2123][2123];
int fact[2123],derang[2123],powde[2123];
int bit[2][2123];
int N=2100;
int update(int typ,int pos,int val){
  pos++;
  while(pos<N){
    bit[typ][pos]+=val;
    pos+=pos&(-pos);
  }
  return 0;
}
int query(int typ,int pos){
  int ans=0;
  pos++;
  while(pos>0){
    ans+=bit[typ][pos];
    pos-=pos&(-pos);
  }
  return ans;
}
int compute(int n,int k){
  if(n==0){
    return 1;
  }
  if(n==1){
    if(k)
      return 0;
    return 1;
  }
  if(k==0)
    return fact[n];
  if(visit[n][k])
    return dp[n][k];
  int ans=0;
  visit[n][k]=1;
  if(k>=2){
    ans+=(k-1)*compute(n-1,k-2);
  }
  ans+=(n-k)*compute(n-1,k-1);
  ans%=mod;
  dp[n][k]=ans;
  return dp[n][k];
}
int gg[2123];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i,j;
  	rep(i,n){
  		rep(j,n){
  			cin>>a[i][j];
        a[i][j]--;
  		}
  	}
  	derang[1]=0;
  	derang[2]=1;
    derang[0]=1;
  	f(i,3,n+10){
  		derang[i]=(i-1)*(derang[i-1]+derang[i-2]);
  		derang[i]%=mod;
  	}
    powde[0]=1;
    fact[0]=1;
    f(i,1,n+10){
      powde[i]=powde[i-1]*derang[n];
      powde[i]%=mod;
      fact[i]=fact[i-1]*i;
      fact[i]%=mod;
    }
    i=0;
    ll ans=0;
    int val;
    rep(j,n){
      update(0,j,1);
    }
    ll bigg=0;
    rep(j,n){
      val=query(0,a[i][j]-1);
      update(0,a[i][j],-1);
      if(val!=0){
        val*=fact[n-1-j];
        val%=mod;
        ans+=val;
      }
    }
    
    ans%=mod;
    ans*=powde[n-1];
    ans%=mod;
    bigg+=ans;
    //cout<<bigg<<endl;
    int twocommon=0,haha,lol;
  	f(i,1,n){
     // cout<<bigg<<endl;
      ans=0;
      rep(j,n){
        update(0,j,1);
        gg[j]=2;
        update(1,j,1);
      }
      lol=n;
  		rep(j,n){
        val=query(0,a[i][j]-1);
        //cout<<val<<endl;
        gg[a[i-1][j]]--;
        if(gg[a[i-1][j]]==1){
          update(1,a[i-1][j],-1);
          lol--;
        }
        if(gg[a[i-1][j]] && a[i-1][j]<a[i][j]){
          val--;
        }
        twocommon=query(1,a[i][j]-1);
        //cout<<twocommon
        if(twocommon){
          haha=twocommon*compute(n-1-j,lol-1);
          haha%=mod;
          ans+=haha;
          ans%=mod;
        }
        if(val-twocommon>0){
          haha=(val-twocommon)*compute(n-1-j,lol);
          haha%=mod;
          ans+=haha;
          ans%=mod;
        }
        update(0,a[i][j],-1);
        gg[a[i][j]]--;
        if(gg[a[i][j]]==1){
          update(1,a[i][j],-1);
          lol--;
        }
  		}
      ans*=powde[n-i-1];
      ans%=mod;
      bigg+=ans;
      bigg%=mod;
      //cout<<bigg<<endl;
  	}
    bigg%=mod;
    cout<<bigg<<endl;
    return 0;   
}