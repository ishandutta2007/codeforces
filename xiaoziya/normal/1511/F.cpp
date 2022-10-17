#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=45,maxt=205,mod=998244353;
int n,m,tot,cnt;
int nxt[maxn][27],ed[maxn],id[maxn][maxn];
string s;
struct matrix{
	int len,wid;
	int a[maxt][maxt];
	matrix operator *(const matrix p){
		matrix res;
		res.len=len,res.wid=p.wid,memset(res.a,0,sizeof(res.a));
		for(int i=1;i<=len;i++)
			for(int j=1;j<=p.wid;j++)
				for(int k=1;k<=wid;k++)
					res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*p.a[k][j])%mod;
		return res;
	}
	matrix operator ^(long long b){
		matrix a=(*this),res;
		res.len=res.wid=len,memset(res.a,0,sizeof(res.a));
		for(int i=1;i<=len;i++)
			res.a[i][i]=1;
		while(b){
			if(b&1)
				res=res*a;
			a=a*a,b>>=1;
		}
		return res;
	}
}T;
void insert(string s){
	int now=1;
	for(int i=0;i<s.size();i++){
		int c=s[i]-96;
		if(nxt[now][c]==0)
			nxt[now][c]=++tot;
		now=nxt[now][c];
	}
	ed[now]=1;
}
void dfs(int a,int b){
	if(a>b){
		dfs(b,a),id[a][b]=id[b][a];
		return ;
	}
	if(id[a][b])
		return ;
	id[a][b]=++cnt;
	for(int i=1;i<=26;i++)
		if(nxt[a][i]&&nxt[b][i]){
			int c=nxt[a][i],d=nxt[b][i];
			dfs(c,d),T.a[id[a][b]][id[c][d]]++;
			if(ed[c])
				dfs(1,d),T.a[id[a][b]][id[1][d]]++;
			if(ed[d])
				dfs(c,1),T.a[id[a][b]][id[c][1]]++;
			if(ed[c]&&ed[d])
				T.a[id[a][b]][1]++;
		}
}
int main(){
	scanf("%d%d",&n,&m),tot=1;
	for(int i=1;i<=n;i++)
		cin>>s,insert(s);
	memset(T.a,0,sizeof(T.a)),dfs(1,1),T.len=T.wid=cnt;
	printf("%d\n",(T^m).a[1][1]);
	return 0;
}