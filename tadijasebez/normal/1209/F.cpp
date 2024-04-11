#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=100050;
const int M=20*N;
int tsz;
vector<pair<int,int>> E[M];
void Add(int u,int v,int i){
	for(int las=v,node;i;i/=10,las=node){
		if(i>9)node=++tsz;
		else node=u;
		E[node].pb({i%10,las});
	}
}
int was[M],ans[M];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	tsz=n;
	for(int i=1,u,v;i<=m;i++)scanf("%i %i",&u,&v),Add(u,v,i),Add(v,u,i);
	for(int i=1;i<=tsz;i++)sort(E[i].begin(),E[i].end());
	queue<set<int>> q;
	q.push({1});was[1]=1;
	while(q.size()){
		set<int> st=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			set<int> nxt;
			for(int u:st)
				for(auto v:E[u])
					if(v.first==i && !was[v.second]){
						was[v.second]=1;
						ans[v.second]=((ll)ans[u]*10+v.first)%mod;
						nxt.insert(v.second);
					}
			if(nxt.size())q.push(nxt);
		}
	}
	for(int i=2;i<=n;i++){
		printf("%i\n",ans[i]);
	}
	return 0;
}