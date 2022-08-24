#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],len,in[110000],s[110000],dfs[110000],low[110000],pd[110000],now,sign,w[110000],size[110000],n,m;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void solve(int k){
	s[++len]=k; dfs[k]=++sign; low[k]=sign; pd[k]=1; in[k]=1;
	for (int i=p[k];i!=-1;i=b[i].next){
		if (i&1) continue;
		int j=b[i].point;
		if (pd[j]==0){
			solve(j); low[k]=min(low[k],low[j]);
		} else if (in[j]) low[k]=min(low[k],dfs[j]);
	}
	if (low[k]==dfs[k]){
		now++;
		while (s[len+1]!=k){
			w[s[len]]=now; in[s[len]]=0; len--; size[now]++;
		}
	}
}
int dfss(int k){
	int num=1; pd[k]=1;
	for (int i=p[k];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) num+=dfss(j);
	}
	return num;
}
int main(){
	scanf("%d%d",&n,&m); len=-1; memset(p,0xff,sizeof p);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	len=0;
	for (int i=1;i<=n;i++) if (pd[i]==0) solve(i); 
	int ans=0; memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++)
		if (size[w[i]]>1&&pd[i]==0) ans+=dfss(i);
	for (int i=1;i<=n;i++) if (pd[i]==0) ans+=dfss(i)-1;
	cout<<ans<<endl; return 0;
}