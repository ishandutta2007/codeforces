
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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
//std::ios::sync_with_stdio(false);   


using namespace std;
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
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

ll depth[200006],vec[200006];
vector< vi > adj(200006);

ll power(ll a,ll b){
	//ll a=a1;
	ll ans=1;
	if(b%2==1)
		ans*=a;
	ans%=mod;
	while(b/2 > 0){
		b=b/2;
		a=a*a;
		a%=mod;
		if(b%2==1)
			ans*=a;
		ans%=mod;
	}
	ans%=mod;
	return ans;
}

ll dfs(ll val,ll prev,ll dept){
	//cout<<"hii"<<endl;
	ll i,ans,vali=-1,flag=1;
	depth[val]=dept;
	rep(i,adj[val].size()){

		if(adj[val][i]!=prev){
			
			if(depth[adj[val][i]]==-1){
				ans=dfs(adj[val][i],val,dept+1);
				if(ans!=-1 && flag){
					 vali=ans;
					 flag=0;
				}
			}
		else if(flag){
			flag=0;
			//cout<<"byeee";
			vali= dept+1-depth[adj[val][i]];
			
		}

		}

	}
	//cout<<vali<<endl;
	//cout<<"leave"<<endl;
	return vali;
}

int main(){
	ll n,i,p,flag=0;
	ll ans=1;
	//cout<<power(2,1121)<<endl;
	cin>>n;
	fill(depth,depth+n+4,-1);
	fill(vec,vec+n+4,-1);
	rep(i,n){
		cin>>p;
		p--;
		vec[i]=p;
		if(vec[p]==i)
			continue;
		adj[p].pb(i);
		adj[i].pb(p);
		

	}
	ll n1=n;
	rep(i,n){
		if(depth[i]==-1){
			
			ll val=dfs(i,-1,0);
			
			if(val==-1)
			{
				
				ans*=2;
				ans%=mod;
				n1-=2;
			}
			else{

				ll value=power(2,val)+mod - 2;
				value%=mod;
				ans*=value;
				n1-=val;
				ans%=mod;
			}
		}
			
	}

	
	ll ans1=power(2,n1);
	ans=ans1*ans;
	ans%=mod;
	cout<<ans<<endl;
	return 0;

}