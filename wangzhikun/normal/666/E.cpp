#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
struct mydata{int x,y;bool operator<(const mydata&b)const{return x<b.x||x==b.x&&y>b.y;}}ans[N];
struct seg{int ls,rs;mydata v;}t[N*20];
struct qq{int l,r,pl,pr;}q[N];
int n,m,Q,last=1,tot=1,tr[N][26],fa[22][N],len[N],rt[N],sz;
vector<int>e[N],g[N],v[N];
char S[N],T[N];
void extend(int c)
{
	int p=last,np=++tot;last=np;len[np]=len[p]+1;
	while (p&&!tr[p][c])tr[p][c]=np,p=fa[0][p];
	if(!p)fa[0][np]=1;
	else
	{
		int q=tr[p][c];
		if (len[q]==len[p]+1)fa[0][np]=q;
		else
		{
			int nq=++tot;
			memcpy(tr[nq],tr[q],sizeof(tr[nq]));
			fa[0][nq]=fa[0][q];fa[0][q]=fa[0][np]=nq;len[nq]=len[p]+1;
			while(p&&tr[p][c]==q)tr[p][c]=nq,p=fa[0][p];
        }
	}
}
void modify(int &x,int l,int r,int p)
{
	if(!x)x=++sz;
	if(l==r){t[x].v.x++;t[x].v.y=l;return;}
	int mid=l+r>>1;
	if(p<=mid)modify(t[x].ls,l,mid,p);else modify(t[x].rs,mid+1,r,p);
	t[x].v=max(t[t[x].ls].v,t[t[x].rs].v);
}
void merge(int &x,int y)
{
	if(!x||!y){x=x+y;return;}
	if(!t[x].ls&&!t[x].rs) {t[x].v.x+=t[y].v.x;return;}
	merge(t[x].ls,t[y].ls);merge(t[x].rs,t[y].rs);
	t[x].v=max(t[t[x].ls].v,t[t[x].rs].v);
}
mydata qry(int x,int l,int r,int ql,int qr)
{
	if(l>=ql&&r<=qr)return t[x].v;
	int mid=l+r>>1;
	if(qr<=mid)return qry(t[x].ls,l,mid,ql,qr);else if(ql>mid)return qry(t[x].rs,mid+1,r,ql,qr);else return max(qry(t[x].ls,l,mid,ql,qr),qry(t[x].rs,mid+1,r,ql,qr));
}
void dfs(int x)
{
	for(int i=0;i<e[x].size();i++)dfs(e[x][i]),merge(rt[x],rt[e[x][i]]);
    for(int i=0;i<v[x].size();i++)ans[v[x][i]]=qry(rt[x],1,m,q[v[x][i]].l,q[v[x][i]].r);
}
int main()
{
	scanf("%s%d",S+1,&m);n=strlen(S+1);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",T+1);int len=strlen(T+1);last=1;
		for (int j=1;j<=len;j++)extend(T[j]-'a'),modify(rt[last],1,m,i);
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].pl,&q[i].pr);g[q[i].pr].push_back(i);}
    for(int i=2;i<=tot;i++)e[fa[0][i]].push_back(i);
    for(int j=1;j<22;j++)for(int i=2;i<=tot;i++)fa[j][i]=fa[j-1][fa[j-1][i]];
    for(int i=1,x=1,cnt=0;i<=n;++i)
    {
		while(x&&!tr[x][S[i]-'a'])x=fa[0][x],cnt=len[x];
		if(!x){x=1;cnt=0;continue;}
		x=tr[x][S[i]-'a'];++cnt;
		for(int ii=0;ii<g[i].size();ii++)
		{
			int y=x,j=g[i][ii];
			if(cnt<q[j].pr-q[j].pl+1)continue;
			for(int k=21;~k;--k)if(len[fa[k][y]]>=q[j].pr-q[j].pl+1)y=fa[k][y];
			v[y].push_back(j);
		}
	}
	dfs(1);
	for(int i=1;i<=Q;i++)if(!ans[i].x)ans[i].y=q[i].l;
	for(int i=1;i<=Q;i++)printf("%d %d\n",ans[i].y,ans[i].x);
	return 0;
}