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
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983 

vector<string> splitstr(string s,char delim){
	int i;
	vector<string> vec;
	string sofar="";
	rep(i,s.length()){
		if(s[i]==delim){
			vec.pb(sofar);
			sofar="";
		}
		else{
			sofar+=s[i];	
		}
	}
	vec.pb(sofar);
	return vec;

}
int WA(){
	cout<<-1<<endl;
	exit(0);
}
vector<vi> adj(12345);
int compid[1234][1234];
int dfs(int cur,int par,int gao){
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		if(compid[gao][cur]!=compid[gao][adj[cur][i]])
			WA();
		dfs(adj[cur][i],cur,gao);
	}
	return 0;
}
int visit[1234];
int dfsgen(int cur){
	visit[cur]=1;
	int i;
	rep(i,adj[cur].size()){
		if(visit[adj[cur][i]]==0)
			dfsgen(adj[cur][i]);
	}
	return 0;
}
int confirmtree(int n){
	dfsgen(0);
	int i;
	rep(i,n){
		if(visit[i]==0)
			WA();
	}
	return 1;
}
int siz[1234][1234];
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i,j,k;
	string s;
	rep(i,n){
		cin>>s;
		vector<string> gg=splitstr(s,'-');
		//cout<<gg.size()<<endl;
		//return 0;
		rep(j,gg.size()){
			vector<string> gao = splitstr(gg[j],':');
			assert(gao.size()==2);
			int sizf=stoi(gao[0]);
			vector<string> foo = splitstr(gao[1],',');
			rep(k,foo.size()){
				int lol = stoi(foo[k]);
			//	cout<<k<<" "<<lol<<endl;
				siz[i][lol-1]=sizf;
				//comp[i][j].pb(lol-1);
				compid[i][lol-1]=j;
			}
		}
	}
	//return 0;
	vii ansvec;
	int edge=0;
	rep(i,n){
		f(j,i+1,n){
			if(siz[i][j]+siz[j][i]==n){
				adj[i].pb(j);
				adj[j].pb(i);
				edge++;
				ansvec.pb(mp(i,j));
			}	
		}
	}
	//return 0;
	if(edge!=n-1){
		cout<<-1<<endl;
		return 0;
	}
	if(confirmtree(n)==0){
		cout<<-1<<endl;
	}
	//return 0;
	rep(i,n){
		rep(j,adj[i].size()){
			dfs(adj[i][j],i,i);
		}
	}
	//return 0;
	cout<<n-1<<endl;
	rep(i,ansvec.size()){
		cout<<ansvec[i].ff+1<<" "<<ansvec[i].ss+1<<endl;
	}

}