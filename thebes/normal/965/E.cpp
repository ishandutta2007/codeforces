#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
priority_queue<int,vector<int>,less<int>> q[MN];
int n,i,j,t[MN][26],dep[MN],nxt,p,id[MN],w[MN],sz[MN];
string s;
int getSz(int n){
	for(int i=0;i<26;i++)
		if(t[n][i]) sz[n]+=getSz(t[n][i]);
	return ++sz[n];
}

void solve(int n){
	for(int i=0;i<26;i++)
		if(t[n][i]) solve(t[n][i]);
	pair<int,int> big(-1,-1);
	for(int i=0;i<26;i++){
		if(!t[n][i]) continue;
		if(sz[t[n][i]]>big.first)
			big={sz[t[n][i]],i};
	}
	if(big.second==-1) id[n]=nxt++;
	else id[n]=id[t[n][big.second]];
	for(int i=0;i<26;i++){
		if(!t[n][i]||i==big.second) continue;
		while(q[id[t[n][i]]].size()){
			q[id[n]].push(q[id[t[n][i]]].top());
			q[id[t[n][i]]].pop();
		}
	}
	if(w[n]) q[id[n]].push(dep[n]);
	else if(n) q[id[n]].pop(),q[id[n]].push(dep[n]);
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		cin >> s; p = 0;
		for(j=0;j<s.size();j++){
			if(!t[p][s[j]-'a']) t[p][s[j]-'a']=++nxt;
			p = t[p][s[j]-'a']; dep[p]=j+1;
		}
		w[p] = 1;
	}
	nxt=0; getSz(0); solve(0);
	long long ans = 0;
	while(q[id[0]].size()){
		ans += q[id[0]].top();
		q[id[0]].pop();
	}
	printf("%lld\n",ans);
	return 0;
}