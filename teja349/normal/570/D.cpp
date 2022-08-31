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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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

//std::ios::sync_with_stdio(false); 
struct state{
	int arr[27];
};
int st[500010],en[500010],ver[500010],timer=0,p[500010];
vector<vi> adj(500010);
vector<vii> bfsed(500010);
vector< vector<state> > quer(500010);
char haha[500010];
state asad;
int dfs(int cur,int level){
	int i;
	timer++;
	//lev[cur]=level;
	st[cur]=timer;
	ver[timer]=cur;
	bfsed[level].pb(mp(st[cur],haha[cur]-'a'));
	quer[level].pb(asad);
	rep(i,adj[cur].size()){
		dfs(adj[cur][i],level+1);
	}
	en[cur]=timer;
	return 0;
}

//vector<vector<state>> quer();
int precompute(){
	int i,j,level=0;
	while(!bfsed[level].empty()){
		//return 0;
		rep(i,bfsed[level].size()){
			
			//return 0;
			if(i==0){
				quer[level][i].arr[bfsed[level][i].ss]++;
			}
			else{
				rep(j,26){
					quer[level][i].arr[j]=quer[level][i-1].arr[j];
				}
				quer[level][i].arr[bfsed[level][i].ss]++;

			}
		}
		level++;
	}
	// cout<<"nee";
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	

	//cin>>p[0];
	int i,j,u,h,val1,val2;
	rep(i,26){
		asad.arr[i]=0;
	}	
	//return 0;
	f(i,1,n){
		cin>>p[i];

		p[i]--;
		//cout<<p[i]<<endl;
		adj[p[i]].pb(i);
	}
	rep(i,n){
		cin>>haha[i];	

	}

	//return 0;
	dfs(0,0);
	//return 0;
	precompute();
	//return 0;
	vii::iterator it1,it2;
	pii papa;
	while(m--){
		cin>>u>>h;
		u--;
		h--;
		papa=mp(st[u],-1);
		int answ[30]={0};
		int counti=0;

		it1=lower_bound(bfsed[h].begin(),bfsed[h].end(),papa);
		papa.ss=40;
		papa.ff=en[u];
		val1=it1-bfsed[h].begin();
		it2=lower_bound(bfsed[h].begin(),bfsed[h].end(),papa);
		
		val2=it2-bfsed[h].begin();
		//val2--;
		if(val2==0){
			cout<<"Yes"<<endl;
			//return 0;
		}
		else if(val1==0){
			//cout<<"YPYUP"<<val2<<endl;
			rep(j,26){
				answ[j]+=quer[h][val2-1].arr[j];
			}
			rep(j,26){
				if(answ[j]&1){
					counti++;
				}
			}
			//cout<<counti<<endl;
			if(counti>=2)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
		else{
			rep(j,26){
				answ[j]+=quer[h][val2-1].arr[j]-quer[h][val1-1].arr[j];
			}
			rep(j,26){
				if(answ[j]&1){
					counti++;
				}
			}
			if(counti>=2)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	}


}