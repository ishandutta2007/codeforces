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
vector<vector< pair<string,int> > > adj(12345);
map<string,int> mapi;
map<int,string> mapinv;
set< string > seti;
string ster[12345];
int counti=0;
int visit[2000]={0};
map<string ,int> map2;
int tryache(int i);
int tryaccom(int i){
	//cout<<"hii";
	//cout<<adj[i][0].ff<<endl;
	int j;
	if(map2.find(mapinv[i])==map2.end() && map2.find(adj[i][0].ff)==map2.end()){
		return 1;
	}
	else if(map2.find(mapinv[i])!=map2.end()){
		//cout<<"gddf";
		rep(j,1050){
			visit[j]=0;
		}
		if(tryache(map2[mapinv[i]])){

			map2[mapinv[i]]=i;
			ster[adj[i][0].ss]=mapinv[i];
			return 0;
		}


	}
	if(map2.find(adj[i][0].ff)!=map2.end()){

		rep(j,1050){
			visit[j]=0;
		}
		if(tryache(map2[adj[i][0].ff])){
			map2[adj[i][0].ff]=i;
			ster[adj[i][0].ss]=adj[i][0].ff;
			return 0;
		}
	}
	return 1;

}
int tryache(int i){
	if(visit[i])
		return 0;
	visit[i]=1;
	if(ster[adj[i][0].ss]==mapinv[i] && ster[adj[i][0].ss]==adj[i][0].ff)
		return 0;
	if(ster[adj[i][0].ss]==mapinv[i]){
		if(seti.find(adj[i][0].ff)==seti.end()){
			ster[adj[i][0].ss]=adj[i][0].ff;
			seti.insert(adj[i][0].ff);
			map2[adj[i][0].ff]=i;

			return 1;
		}
		else if(map2.find(adj[i][0].ff)!=map2.end()){

			if(tryache(map2[adj[i][0].ff])){
				ster[adj[i][0].ss]=adj[i][0].ff;
				
				map2[adj[i][0].ff]=i;

				return 1;
			}
			else{
				return 0;
			}
		}
	}
	else if(map2.find(mapinv[i])!=map2.end()){
		if(tryache(map2[mapinv[i]])){
			ster[adj[i][0].ss]=mapinv[i];
			
			map2[mapinv[i]]=i;

			return 1;
		}
		else{
			return 0;
		}
	}
	return 0;

}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,j;
	cin>>n;
	string s1,s2,s="";
	rep(i,n){
		cin>>s1>>s2;
		s=s1.substr(0,2);
		s1=s1.substr(0,3);
		s+=s2[0];

		if(mapi.find(s1)==mapi.end()){
			mapi[s1]=counti;
			mapinv[counti]=s1;
			counti++;
		}
		adj[mapi[s1]].pb(mp(s,i));

	}
	rep(i,counti){
		if(adj[i].size()==1)
			continue;
		rep(j,adj[i].size()){
			if(seti.find(adj[i][j].ff)!=seti.end()){
				cout<<"NO"<<endl;
				return 0;
			}
			else{
				ster[adj[i][j].ss]=adj[i][j].ff;
				seti.insert(adj[i][j].ff);
			}
		}
	}
	rep(i,counti){
		if(adj[i].size()==1){
			if(seti.find(mapinv[i])==seti.end()){
				ster[adj[i][0].ss]=mapinv[i];
				seti.insert(mapinv[i]);
				map2[mapinv[i]]=i;
				//cout<<mapinv[i]<<endl;
			}
			else if(seti.find(adj[i][0].ff)==seti.end()){
				ster[adj[i][0].ss]=adj[i][0].ff;
				seti.insert(adj[i][0].ff);
				map2[adj[i][0].ff]=i;
			}
			else if(tryaccom(i)){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	rep(i,n){
		cout<<ster[i]<<endl;
	}
}