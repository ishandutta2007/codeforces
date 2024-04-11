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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
int dist[3003][3003]={0},trans[3003][3003]={0};
vector<vi> adj(3003);
vector<vii> normaq(3003),normaqw(3003);
vector< set<int> > dummy(3003);
ll iinf;
int n,m;
int compute(int node){
	//int dist[4000]={0};
	int visit[3003]={0};
	queue<int> que;
	que.push(node);
	visit[node]=1;
	dist[node][node]=0;
	int i;
	while(!que.empty()){
		int pre=que.front();
		que.pop();
		rep(i,adj[pre].size()){
			if(!visit[adj[pre][i]]){
				dist[node][adj[pre][i]]=dist[node][pre]+1;
				visit[adj[pre][i]]=1;
				que.push(adj[pre][i]);
			}
		}

	}
	return 0;

}
int valid(int a,int b,int c,int d){
	int arr[10],i,j;
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	arr[3]=d;
	rep(i,4){
		rep(j,4){
			if(i==j)
				continue;
			if(arr[i]==arr[j]){
				return 0;
			}
		}
	}
	return 1;

}
int cheker(int p,int q){
	int lol=iinf,i,j;

	rep(i,normaqw[p].size()){
		rep(j,normaq[q].size()){
			if(valid(p,q,normaqw[p][i].ff,normaq[q][j].ff)){
				//cout<<normaqw[p][i].ff<<" "<<normaq[q][j].ff<<endl;
				if(lol<normaqw[p][i].ss+normaq[q][j].ss){
					lol=normaqw[p][i].ss+normaq[q][j].ss;
				}
			}
		}
	}
	return lol;
}
int bigcompute(int p,int q){
	int lol=iinf,i,j;
	pii papa;
	papa.ff=-1;
	papa.ss=-1;
	rep(i,normaqw[p].size()){
		rep(j,normaq[q].size()){
			if(valid(p,q,normaqw[p][i].ff,normaq[q][j].ff)){
				if(lol<normaqw[p][i].ss+normaq[q][j].ss){
					lol=normaqw[p][i].ss+normaq[q][j].ss;
					//cout<<"yii"<<endl;
					papa=mp(normaqw[p][i].ff,normaq[q][j].ff);
				}
			}
		}
	}
	cout<<papa.ff+1<<" ";
	return papa.ss;
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,j,u,v;
	cin>>n>>m;
	iinf=inf;
	iinf*=-1;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		if(u==v)
			continue;
		dummy[u].insert(v);
	}
	set<int> ::iterator it;
	rep(i,n){
		for(it=dummy[i].begin();it!=dummy[i].end();it++){
			adj[i].pb(*it);
		}
	}
	rep(i,n){
		compute(i);
	}
	rep(i,n){
		rep(j,n){
			if(dist[i][j]==0){

				dist[i][j]=iinf;
			}
			trans[j][i]=dist[i][j];
		}
	}
	int maxi,haha;
	rep(i,n){
		maxi=0;
		haha=-1;
		rep(j,n){
			if(dist[i][j]>maxi){
				maxi=dist[i][j];
				haha=j;
			}
		}
		if(haha!=-1){
			j=haha;
		normaq[i].pb(mp(j,maxi));
		dist[i][j]=iinf;
		}
		
		maxi=0;
		haha=-1;
		rep(j,n){
			if(dist[i][j]>maxi){
				maxi=dist[i][j];
				haha=j;
			}
		}

		if(haha!=-1){
			j=haha;
		normaq[i].pb(mp(j,maxi));
		dist[i][j]=iinf;
		}
		maxi=0;
		haha=-1;
		rep(j,n){
			if(dist[i][j]>maxi){
				maxi=dist[i][j];
				haha=j;
			}
		}

		if(haha!=-1){
			j=haha;
		normaq[i].pb(mp(j,maxi));
		dist[i][j]=iinf;
		}
		maxi=0;
		
		rep(j,normaq[i].size()){
			dist[i][normaq[i][j].ff]=normaq[i][j].ss;
		}
	}
	rep(i,n){
		maxi=0;
		haha=-1;
		rep(j,n){
			if(trans[i][j]>maxi){
				maxi=trans[i][j];
				haha=j;
			}
		}
		if(haha!=-1){
			j=haha;
		normaqw[i].pb(mp(j,maxi));
		trans[i][j]=iinf;
		}
		maxi=0;
		haha=-1;
		rep(j,n){
			if(trans[i][j]>maxi){
				maxi=trans[i][j];
				haha=j;
			}
		}
		if(haha!=-1){
			j=haha;
		normaqw[i].pb(mp(j,maxi));
		trans[i][j]=iinf;
		}
		maxi=0;
		haha=-1;
		rep(j,n){
			if(trans[i][j]>maxi){
				maxi=trans[i][j];
				haha=j;
			}
		}
		if(haha!=-1){
			j=haha;
		normaqw[i].pb(mp(j,maxi));
		trans[i][j]=iinf;
		}
		
		maxi=0;
		
		rep(j,normaqw[i].size()){
			trans[i][normaqw[i][j].ff]=normaqw[i][j].ss;
		}
	}
	int lol=iinf;
	pii papa;
	rep(i,n){
		rep(j,n){
			//i=1;
			//j=0;

			if(dist[i][j]>0){
				//cout<<"yii"<<endl;
				int val=cheker(i,j);
				if(lol<val+dist[i][j]){
					lol=val+dist[i][j];
					papa=mp(i,j);
				}
			}
			//break;
			
		}
		//break;
	}
	//cout<<dist[1][0]<<" sdsd" <<endl;
	//cout<<lol<<endl;
	int val=bigcompute(papa.ff,papa.ss);
	cout<<papa.ff+1<<" "<<papa.ss+1<<" "<<val+1<<endl;
}