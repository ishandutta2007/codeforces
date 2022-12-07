#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
struct edge{
	int to,next,fl;
}e[N*2];
int head[N],deg[N],tot;
int a[N],s[N],q[N],n,m;
int ban[N],sg[N];
void add(int x,int y,int fl){
	e[++tot]=(edge){y,head[x],fl};
	head[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x,0); 
		add(x,y,1);
		++deg[x];
	}
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].fl==1) ban[sg[e[i].to]]=1;
		for (;ban[sg[x]];++sg[x]);
		s[sg[x]]^=a[x];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].fl==1) ban[sg[e[i].to]]=0;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].fl==0)
				if (!--deg[e[i].to])
					q[++t]=e[i].to;
	}
	int sum=0;
	For(i,0,n) if (s[i]) ++sum;
	if (!sum) return puts("LOSE"),0;
	puts("WIN");
	int mxp=-1;
	For(i,1,n) if (s[sg[i]])
		if (mxp==-1||sg[i]>sg[mxp]) mxp=i;
	For(i,1,n) if (sg[i]==sg[mxp])
		if ((s[sg[i]]^a[i])<a[i]){
			a[i]=s[sg[i]]^a[i]; s[sg[i]]=0;
			for (int j=head[i];j;j=e[j].next)
				if (e[j].fl==1&&s[sg[e[j].to]]){
					a[e[j].to]=s[sg[e[j].to]]^a[e[j].to];
					s[sg[e[j].to]]=0;
				}
			For(j,1,n) printf("%d ",a[j]);
			puts("");
		}
}