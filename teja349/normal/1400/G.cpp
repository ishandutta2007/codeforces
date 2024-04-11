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

int comp=1;
vector<vi> adj(312345),vec(123);
vector<vii> adds(312345),removs(312345);
int l[312345],r[312345],a[312345],b[312345],sp[312345],visit[312345];
int q[123],cnt[312345],boo[123];

int addn[312345],removn[312345];
int dfs(int cur){
	vec[comp].pb(cur);
	int i;
	visit[cur]=comp;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]])
			dfs(adj[cur][i]);
	}
	return 0;
}

ll haha[123][123];
ll gao[123],temp[123];
int prodsize;
int getprod(){
	int i,j,k;
	rep(j,prodsize+1){
		gao[j]=0;
	}
	prodsize=1;
	gao[0]=1;
	int maxi=0;
	f(i,1,comp){
		maxi=0;
		rep(j,boo[i]){
			if(haha[i][j]!=0){
				maxi=j;
				rep(k,prodsize){
					temp[k+j]+=gao[k]*haha[i][j];
				}
			}
		}
		prodsize+=maxi;
		rep(j,prodsize){
			gao[j]=temp[j];
			gao[j]%=mod;
			temp[j]=0;
		}
	}
	return 0;
}

// N choose r computing basic   do initcombi();
ll inv[300003],mult[300003],invmult[300003];
// gcd
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}
// extended gcd algorithm
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

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j,k;
    rep(i,n){
    	cin>>l[i]>>r[i];
    }
    rep(i,m){
    	cin>>a[i]>>b[i];
    	a[i]--;
    	b[i]--;
    	adj[a[i]].pb(b[i]);
    	adj[b[i]].pb(a[i]);
    	sp[a[i]]=i+1;
    	sp[b[i]]=i+1;
    }
    rep(i,n){
    	if(sp[i]==0){
    		addn[l[i]]++;
    		removn[r[i]]++;
    	}
    }
    rep(i,n){
    	if(sp[i] && !visit[i]){
    		//cout<<i<<endl;
    		dfs(i);
    		int lol=vec[comp].size();
    		boo[comp]=lol;
    		rep(j,lol){
    			q[j]=vec[comp][j];
    		}
    		rep(j,(1<<lol)){
    			int flag=0,maxl=1,minr=n,sizi=0;
				rep(k,lol){
					if((1<<k)&j){
						cnt[q[k]]++;
						maxl=max(maxl,l[q[k]]);
						minr=min(minr,r[q[k]]);
						sizi++;
					}
				}

				rep(k,m){
					if(cnt[a[k]] && cnt[b[k]]){
						flag=1;
					}
				}
				rep(k,m){
					cnt[a[k]]=0;
					cnt[b[k]]=0;
				}
				if(flag)
					continue;
				if(maxl>minr)
					continue;

				adds[maxl].pb(mp(comp,sizi));
				removs[minr].pb(mp(comp,sizi));
    		}
    		comp++;
    	}
    }
    initcombi();
    int active=0;
    ll ans=0;
    f(i,1,n+1){
    	active+=addn[i];
    	rep(j,adds[i].size()){
    		//cout<<"da"<<endl;
    		haha[adds[i][j].ff][adds[i][j].ss]++;
    	}
    	getprod();
    	
    	rep(j,prodsize){
    		ans+=combination(active,i-j)*gao[j];
    		ans%=mod;	
    	}
    	rep(j,removs[i].size()){
    		haha[removs[i][j].ff][removs[i][j].ss]--;
    	}
    	//cout<<active<<" "<<i<<" "<<prodsize<<" "<<ans<<" "<<gao[0]<<endl;
    	active-=removn[i];

    }

    cout<<ans<<endl;
    return 0;   
}