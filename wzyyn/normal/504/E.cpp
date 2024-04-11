#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define y1 wzpakking
using namespace std;
const int N=300005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int sz[N],fa[N],dep[N];
int dfn[N],ed[N],top[N];
int pos[N];
pii q1[50],q2[50];
char s[N],t[N*2];
int cnt[N*2],x[N*2],y[N*2];
int SA[N*2],rk[N*2],lg[N*2];
int st[N*2][20];
bool cmp(int i,int j,int k,int n){
	return y[i]!=y[j]||((i+k>n?-1:y[i+k])!=(j+k>n?-1:y[j+k]));
}
void build_SA(int n){
	int m=26;
	For(i,1,n) cnt[x[i]=t[i]-'a'+1]++;
	For(i,1,m) cnt[i]+=cnt[i-1];
	Rep(i,n,1) SA[cnt[x[i]]--]=i;
	for (int k=1;k<n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,1,m) cnt[i]=0;
		For(i,1,n) cnt[x[y[i]]]++;
		For(i,1,m) cnt[i]+=cnt[i-1];
		Rep(i,n,1) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=cmp(SA[i-1],SA[i],k,n));
		if (m==n) break;
	}
	For(i,1,n) rk[SA[i]]=i;
	//For(i,1,n) printf("%d ",SA[i]); puts("");
	For(i,2,n) lg[i]=lg[i/2]+1;
	int p=0;
	For(i,1,n) if (rk[i]!=1){
		p-=(p!=0);
		for (;t[i+p]==t[SA[rk[i]-1]+p];++p);
		//printf("%d %d\n",rk[i],p);
		st[rk[i]][0]=p;
	}
	For(i,1,19) For(j,1,n-(1<<i)+1)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
int LCP(int x,int y){
	x=rk[x]; y=rk[y];
	if (x==y) return n;
	if (x>y) swap(x,y);
	int k=lg[y-(++x)+1];
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	dfn[x]=ed[x]=++*dfn;
	t[*dfn]=t[2*n+1-(*dfn)]=s[x];
	pos[*dfn]=x;
	int k=0; top[x]=tp;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k){
		dfs2(k,tp);
		ed[x]=ed[k];
	}
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}
int getseq(int x,int y,pii *q){
	static pii tmp[20];
	static int tp1,tp2;
	tp1=tp2=0;
	for (;top[x]!=top[y];)
		if (dep[top[x]]>=dep[top[y]]){
			q[++tp1]=pii(x,top[x]);
			x=fa[top[x]];
		}
		else{
			tmp[++tp2]=pii(top[y],y);
			y=fa[top[y]];
		}
	q[++tp1]=pii(x,y);
	reverse(tmp+1,tmp+tp2+1);
	For(i,1,tp2) q[++tp1]=tmp[i];
	return tp1;
}
bool work(pii &x,pii &y,int &p1,int &p2,int &ans){
	int len1=abs(dfn[x.fi]-dfn[x.se])+1;
	int len2=abs(dfn[y.fi]-dfn[y.se])+1;
	int pp1=(dfn[x.fi]<dfn[x.se]?dfn[x.fi]:2*n+1-dfn[x.fi]);
	int pp2=(dfn[y.fi]<dfn[y.se]?dfn[y.fi]:2*n+1-dfn[y.fi]);
	int L=min(LCP(pp1,pp2),min(len1,len2));
	//printf("Q %d %d %d %d %d %d %d %d\n",x.fi,x.se,y.fi,y.se,pp1,pp2,L,ans);
	ans+=L;
	if (L==len1) ++p1;
	else if (dfn[x.fi]<dfn[x.se])
		x.fi=pos[dfn[x.fi]+L];
	else x.fi=pos[dfn[x.fi]-L];
	if (L==len2) ++p2;
	else if (dfn[y.fi]<dfn[y.se])
		y.fi=pos[dfn[y.fi]+L];
	else y.fi=pos[dfn[y.fi]-L];
	return L==min(len1,len2);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%s",&n,s+1);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	//printf("%s\n",t+1);
	build_SA(2*n);
	scanf("%d",&Q);
	while (Q--){
		int x1,y1,x2,y2,sz1,sz2,ans=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		sz1=getseq(x1,y1,q1);
		sz2=getseq(x2,y2,q2);
		int p1=1,p2=1;
		for (;p1<=sz1&&p2<=sz2;)
			if (!work(q1[p1],q2[p2],p1,p2,ans))
				break;
		printf("%d\n",ans);
	}
}