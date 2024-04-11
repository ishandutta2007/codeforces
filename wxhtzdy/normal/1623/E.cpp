#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int N=200050;
int n,k,ls[N],rs[N],ok[N];
char s[N];
vector<int> ord;
vector<pii> E[N];
void DFS(int u){
	if(ls[u])DFS(ls[u]);
	ord.pb(u);
	if(rs[u])DFS(rs[u]);
}
bool dup[N];
void Solve(int u,int dep){
	if(u==0||dep>k)return;
	Solve(ls[u],dep+1);
	if(dup[ls[u]])dup[u]=1;
	else if(ok[u])dup[u]=1,k-=dep;
	if(dup[u])Solve(rs[u],1);
}
int main(){
	scanf("%i%i",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%i%i",&ls[i],&rs[i]);
	DFS(1);
	int lst=n-1;
	for(int i=n-2;i>=0;i--){
		if(s[ord[i]]!=s[ord[i+1]])lst=i+1;
		if(s[ord[i]]<s[ord[lst]])ok[ord[i]]=1;
	}
	Solve(1,1);
	for(int j=0;j<n;j++){
		int i=ord[j];
		printf("%c",s[i]);
		if(dup[i])printf("%c",s[i]);
	}
	return 0;
}