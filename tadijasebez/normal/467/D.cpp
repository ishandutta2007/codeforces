#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>
#define pb push_back
void operator += (pii &a,pii b){
	a.first+=b.first;
	a.second+=b.second;
}
map<string,vector<string>> E;
vector<pair<pii,string>> all;
map<string,pii> mn;
set<string> p;
void Add(string s){
	if(p.count(s))return;
	p.insert(s);
	all.pb({{count(s.begin(),s.end(),'r'),s.size()},s});
}
void Union(string x,string y){
	E[y].pb(x);
}
void lo(string &a){
	for(char &c:a)c=tolower(c);
}
void DFS(string u,pii w){
	if(mn.count(u))return;
	mn[u]=w;
	for(string v:E[u])DFS(v,w);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	vector<string> a(n);
	for(auto &i:a)cin>>i,lo(i),Add(i);
	cin>>m;
	while(m--){
		string u,v;
		cin>>u>>v;
		lo(u);Add(u);
		lo(v);Add(v);
		Union(u,v);
	}
	sort(all.begin(),all.end());
	for(auto z:all)DFS(z.second,z.first);
	pii ans={0,0};
	for(auto i:a)ans+=mn[i];
	cout<<ans.first<<" "<<ans.second<<"\n";
	return 0;
}