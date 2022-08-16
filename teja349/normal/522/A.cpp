
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


vector< vi > adj(123456);

int change(string &s);

int height(int cur,int prev){
	int maxi=0,i;
	if(adj[cur].size()==1 && prev!=-1)
		return 1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			int h=height(adj[cur][i],cur);
			maxi=max(maxi,h);
			//cout<<maxi<<endl;
		}
	}
	return 1+maxi;
}


int main(){
	int i,n,u,v,flag,counti=0,j;
	map< string,int > map1;
	cin>>n;
	rep(i,n){
		string s,s1,s2;
		int flag=1;
		cin>>s>>s1>>s2;
		//change(s);
		rep(j,s.size()){
			if('a'<=s[j] && s[j]<='z'){
				s.at(j)=s[j]-32;
			}
			else{
				s[j]=s[j];
			}
		}	
		//change(s2);
		rep(j,s2.size()){
			if('a'<=s2[j] && s2[j]<='z'){
				s2.at(j)=s2[j]-32;
			}
			else{
				s2[j]=s2[j];
			}
		}	
		//cout<<s<<"    "<<s2<<endl;
		if(map1.find(s)!=map1.end()){
			u=map1[s];

		}
		else{
			u=counti++;
			map1[s]=u;
			//cout<<u<<endl;
		}
		if(map1.find(s2)!=map1.end()){
			v=map1[s2];
		}
		else{
			v=counti++;
			map1[s2]=v;
		}
		
		adj[u].pb(v);
		adj[v].pb(u);
		
	}
	//cout<<adj[2].size()<<"  ad "<<endl;
	cout<<height(map1["POLYCARP"],-1)<<endl;
	//cout<<counti<<endl;
}


int change(string &s){
	string s1,i;
	//string s=s2
	
	return 0;
}