#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
string s;
int n,ans;
int T,A[1010],B[1010],cnt,head[2010],nxt[100010],dis[100010],id;
bool w[100010];
void link(int a,int b,int c){
	nxt[++id]=head[a],head[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=head[b],head[b]=id,dis[id]=a,w[id]=c;
}
int power[2010];
bool vis[2010],col[2010];
bool dfs(int x){
	for(int i=head[x];i;i=nxt[i]){
		if(!vis[dis[i]]){
			vis[dis[i]]=1;
			col[dis[i]]=col[x]^w[i];
			if(dfs(dis[i]))	return 1;
		}
		else if(col[dis[i]]^col[x]^w[i])	return 1;
	}
	return 0;
}
int main(){
	cin>>s;
	n=s.size();
	s=" "+s;
	power[0]=1;
	for(int i=1;i<=2000;++i)	power[i]=power[i-1]*2%MOD;
	for(int S=2;S<=n;++S){
		memset(head,0,sizeof(head));
		id=cnt=0;
		T=cnt++;
		for(int i=S;i<=n;++i)	A[i]=cnt++;
		for(int i=1;i<=n;++i)	B[i]=cnt++;
		link(B[1],T,1);link(A[S],T,1);
		for(int i=S;i<=n;++i){
			if(s[i]=='0')		link(A[i],B[i],0);
			else if(s[i]=='1')	link(A[i],B[i],1);
		}
		for(int i=1;i<S;++i){
			if(s[i]=='0')		link(B[i],T,0);
			else if(s[i]=='1')	link(B[i],T,1);
		}
		for(int i=S,j=n;i<j;++i,--j)	link(A[i],A[j],0);
		for(int i=1,j=n;i<j;++i,--j)	link(B[i],B[j],0);
		memset(vis,0,sizeof(vis));
		int C=0;
		for(int i=0;i<cnt;++i)
			if(!vis[i]){
				++C;
				if(dfs(i)){
					C=-1;
					break;
				}
			}
		if(~C)	ans=(ans+power[C-1])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}