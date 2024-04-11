#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
vector<int> G[100010];
const int N = 5000050;
int n,m,d,dp[N] = {0},dfn[100010],low[100010],col[100010],tim = 1,tot = 1,rep[100010],tot2 = 1,innerv[N];
char open[100010][60];
int stk[100010],stn = 0;
void tarjan(int x){
	dfn[x] = low[x] = tim;tim+=1;
	stk[stn] = x;stn++;
	for(auto ct:G[x]){
		if(!dfn[ct]){
			tarjan(ct);
			low[x] = min(low[x],low[ct]);
		}else{
			if(!col[ct])low[x] = min(low[x],dfn[ct]);
		}
	}
	//cout<<x<<' '<<low[x]<<' '<<dfn[x]<<endl;
	if(low[x] == dfn[x]){
		rep[tot] = x;
		while(stn){
			stn-=1;
			col[stk[stn]] = tot;
			if(x == stk[stn])break;
		}
		tot+=1;
	}
}
int ored[100010][60] = {0},vis[100010],csum;
void dfs(int x,int c,int ccol,int cred){
	ored[x][c] = cred;
	if(open[x][c] == '1' && vis[x]!=cred){
		csum+=1;
		vis[x] = cred;
	}
	int cad = (c == d-1)?0:c+1;
	for(auto ct : G[x])
		if(col[ct] == ccol && !ored[ct][cad])
			dfs(ct,cad,ccol,cred);
}
int st[100010],ed[100010],ad[100],cd[N];
vector<int> G2[N];
int main() {
	read(n);read(m);read(d);
	for(int i=0;i<d;i++)ad[i] = (i+1)%d;
	for(int i=0;i<m;i++){
		read(st[i]);read(ed[i]);
		G[st[i]].push_back(ed[i]);
	}
	for(int i=1;i<=n;i++)scanf("%s",open[i]);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	//for(int i=1;i<=n;i++)cout<<col[i]<<endl;
	for(int i=0;i<tot;i++){
		for(int st=0;st<d;st++){
			if(!ored[rep[i]][st]){
				csum = 0;
				dfs(rep[i],st,i,tot2);
				innerv[tot2++] = csum;
			}
		}
	}
	for(int i=0;i<m;i++){
		int cu = st[i],cv = ed[i];
		for(int j=0;j<d;j++){
			if(ored[cu][j] == ored[cv][ad[j]]) continue;
			cd[ored[cu][j]]+=1;
			G2[ored[cv][ad[j]]].push_back(ored[cu][j]);
		}
	}
	queue<int> cq;
	for(int i=1;i<tot2;i++) if(cd[i] == 0) cq.push(i);
	while(!cq.empty()){
		int cc = cq.front();cq.pop();
		dp[cc] += innerv[cc];
		for(auto ct:G2[cc]){
			dp[ct] = max(dp[ct],dp[cc]);
			cd[ct]-=1;
			if(cd[ct] == 0)cq.push(ct);
		}
	}
	cout<<dp[ored[1][0]]<<endl;
	return 0;
}