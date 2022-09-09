#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void ckmx(ll &a,ll b){a=max(a,b);}
const int M=1050;
const int N=400050;
const int A=14;
const int H=1<<A;
const ll inf=9e18;
ll dp[2][M][H],sum[M],ssm[M];
int go[M][A],root,link[M],tsz,nxt[M];
void cl(int p,int pc){
	for(int j=0;j<H;j++)if(__builtin_popcount(j)==pc)
		for(int i=1;i<=tsz;i++)
			dp[p][i][j]=-inf;
}
void AddString(int &c,char s[],int n,int cost){
	if(!c)c=++tsz;
	if(n)AddString(go[c][s[0]-'a'],s+1,n-1,cost);
	else sum[c]+=cost;
}
void BuildAhoCorasick(){
	queue<int> q;
	link[root]=root;
	for(int i=0;i<A;i++){
		if(go[root][i]){
			q.push(go[root][i]);
			link[go[root][i]]=root;
		}else go[root][i]=root;
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		sum[u]+=sum[link[u]];
		for(int i=0;i<A;i++){
			if(go[u][i]){
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
			}else go[u][i]=go[link[u]][i];
		}
	}
}
char s[M],t[N];
int main(){
	int k,cost;
	scanf("%i",&k);
	while(k--)scanf("%s %i",s,&cost),AddString(root,s,strlen(s),cost);
	BuildAhoCorasick();
	scanf("%s",t+1);
	int n=strlen(t+1),now=1,las=0;
	cl(now,0);
	dp[now][root][0]=0;
	vector<int> ids={0};
	for(int i=1;i<=n;i++)if(t[i]=='?')ids.pb(i);
	ids.pb(n+1);
	for(int j=1;j<ids.size();j++){
		swap(now,las);
		cl(now,j-1);
		for(int i=1;i<=tsz;i++){
			int node=i;ll sm=0;
			for(int z=ids[j-1]+1;z<ids[j];z++)node=go[node][t[z]-'a'],sm+=sum[node];
			nxt[i]=node;
			ssm[i]=sm;
		}
		for(int mask=0;mask<H;mask++)if(__builtin_popcount(mask)==j-1)
			for(int i=1;i<=tsz;i++){
				ckmx(dp[now][nxt[i]][mask],dp[las][i][mask]+ssm[i]);
			}
		if(j+1!=ids.size()){
			swap(now,las);
			cl(now,j);
			for(int mask=0;mask<H;mask++)if(__builtin_popcount(mask)==j-1)
				for(int i=1;i<=tsz;i++){
					for(int z=0;z<A;z++)if(!(mask>>z&1)){
						ckmx(dp[now][go[i][z]][mask|(1<<z)],dp[las][i][mask]+sum[go[i][z]]);
					}
				}
		}
	}
	ll ans=-inf;
	for(int i=1;i<=tsz;i++)
		for(int mask=0;mask<H;mask++)
			if(__builtin_popcount(mask)==(int)ids.size()-2)
				ckmx(ans,dp[now][i][mask]);
	printf("%lld\n",ans);
	return 0;
}