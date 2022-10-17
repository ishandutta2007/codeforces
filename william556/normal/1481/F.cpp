#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int n,m;
vector<int> e[N],v[N];
int c[N],d[N],D;
vector<int> v1[N],v2[N];
void dfs(int x,int fa){
	d[x]=d[fa]+1,c[d[x]]++;D=max(D,d[x]);
	if(e[x].size()>0)v1[d[x]].push_back(x);
	else v2[d[x]].push_back(x);
	for(int y:e[x])dfs(y,x);
}
int cnt[N],val[N],f[500][N],mark[N];
void dp(){	
	for(int i=1;i<=n;i++)cnt[c[i]]++;
	for(int i=1;i<=n;i++)f[0][i]=-1;
	int o=0;
	for(int i=1;i<=n;i++){
		if(!cnt[i])continue;
		o++;val[o]=i;
		for(int j=0;j<=n;j++)f[o][j]=-1;
		for(int j=0;j<i;j++){
			for(int k=j,lst=-1;k<=n;k+=i){
				if(f[o-1][k]!=-1)lst=k;
				if(lst>=k-i*cnt[i])f[o][k]=lst;
			}
		}
	}
	if(f[o][m]==-1)return;
	for(int i=o,j=m;i>=1;i--){
		cnt[val[i]]=(j-f[i][j])/val[i];
		j=f[i][j];
	}
	for(int i=1;i<=n;i++)if(cnt[c[i]]>0)mark[i]=1,cnt[c[i]]--;
	int A=0;
	for(int i=1;i<=n;i++)A+=mark[d[i]];
	assert(A==m);
	printf("%d\n",D);
	for(int i=1;i<=n;i++)putchar(mark[d[i]]?'a':'b');
	puts("");
	exit(0);
}
char s[N];
int main(){
	n=in(),m=in();
	for(int i=2;i<=n;i++)e[in()].push_back(i);
	dfs(1,0);
	dp();
	int A=m,B=n-m;
	for(int i=1;i<=n;i++){
		if(A>=c[i]){
			for(int x:v1[i])s[x]='a';
			for(int x:v2[i])s[x]='a';
			A-=c[i];
			continue;
		}
		if(B>=c[i]){
			for(int x:v1[i])s[x]='b';
			for(int x:v2[i])s[x]='b';
			B-=c[i];
			continue;
		}
		if(A>=v1[i].size()){
			for(int x:v1[i])s[x]='a';
			A-=v1[i].size();
			for(int x:v2[i]){
				if(A)s[x]='a',A--;
				else s[x]='b',B--;
			}
			continue;
		}
		if(B>=v1[i].size()){
			for(int x:v1[i])s[x]='b';
			B-=v1[i].size();
			for(int x:v2[i]){
				if(B)s[x]='b',B--;
				else s[x]='a',A--;
			}
		}
	}
	assert(A==0&&B==0);
	printf("%d\n",D+1);
	printf("%s\n",s+1);
	return 0;
}