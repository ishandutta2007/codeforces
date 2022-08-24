#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
struct bian{
	int next,point;
}b[210000];
const int N=110000;
int w[N],p[N],len;
void ade(int k1,int k2){
	//cout<<"ade "<<k1<<" "<<k2<<endl;
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
int n,m,h;
int in[N],pd[N],where[N],size[N],ou[N],s[N],head,now,sign,dfs[N],low[N];
void dfs1(int k1){
	s[++head]=k1; in[k1]=1; pd[k1]=1; dfs[k1]=++sign; low[k1]=dfs[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			dfs1(j); low[k1]=min(low[k1],low[j]);
		} else if (in[j]) low[k1]=min(low[k1],dfs[j]);
	}
	if (low[k1]==dfs[k1]){
		now++;
		while (1){
			in[s[head]]=0; where[s[head]]=now; size[now]++;
			head--; if (s[head+1]==k1) break;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if ((w[k1]+1)%h==w[k2]) ade(k1,k2);
		if ((w[k2]+1)%h==w[k1]) ade(k2,k1);
	}
	for (int i=1;i<=n;i++) if (pd[i]==0) dfs1(i);
	for (int k=1;k<=n;k++)
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (where[j]!=where[k]) ou[where[k]]++;
		}
	int ans=n+1,whe=0;
	for (int i=1;i<=now;i++) if (ou[i]==0&&size[i]<ans){
		ans=size[i]; whe=i;
	} 
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) if (where[i]==whe) printf("%d ",i);
	puts(""); return 0;}