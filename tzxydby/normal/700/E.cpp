#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,ch[N][26],f[N],l[N],las=1,sz=1,t[N],a[N],rt[N<<5],lc[N<<5],rc[N<<5],c,dp1[N],dp2[N],pos[N],ans=1;
char s[N];
void ins(int &k,int l,int r,int x)
{
	if(!k) k=++c;
	if(l==r)
		return;
	int mid=l+r>>1;
	if(x<=mid) ins(lc[k],l,mid,x);
	else ins(rc[k],mid+1,r,x);
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y) return x^y;
	int k=++c;
	if(l==r)
		return k;
	int mid=l+r>>1;
	lc[k]=merge(lc[x],lc[y],l,mid);
	rc[k]=merge(rc[x],rc[y],mid+1,r);
	return k;
}
int query(int k,int l,int r,int a,int b)
{
	if(!k) return 0;
	if(l==a&&r==b)
		return 1;
	int mid=l+r>>1;
	if(b<=mid) return query(lc[k],l,mid,a,b);
	else if(a>mid) return query(rc[k],mid+1,r,a,b);
	else return query(lc[k],l,mid,a,mid)|query(rc[k],mid+1,r,mid+1,b);
}
void add(int x,int id)
{
	int c=++sz,p=las;
	l[c]=l[p]+1,pos[c]=id;
	ins(rt[c],1,n,id);
	while(p&&!ch[p][x])
	{
		ch[p][x]=c;
		p=f[p];
	}
	if(!p)
		f[c]=1;
	else
	{
		int q=ch[p][x];
		if(l[p]+1==l[q])
			f[c]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			f[nq]=f[q],l[nq]=l[p]+1;
			pos[nq]=pos[q];
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[c]=f[q]=nq;
		}
	}
	las=c;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		add(s[i]-'a',i);
	for(int i=1;i<=sz;i++)
		t[l[i]]++;
	for(int i=1;i<=sz;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=sz;i++)
		a[t[l[i]]--]=i;
	for(int i=sz;i>1;i--)
		rt[f[a[i]]]=merge(rt[f[a[i]]],rt[a[i]],1,n);
	for(int i=1;i<=sz;i++)
	{
		int u=a[i];
		if(f[u]==1)
		{
			dp1[u]=1;
			dp2[u]=u;
			continue;
		}
		if(query(rt[dp2[f[u]]],1,n,pos[u]-l[u]+l[dp2[f[u]]],pos[u]-1))
		{
			dp1[u]=dp1[f[u]]+1;
			dp2[u]=u;
		}
		else
		{
			dp1[u]=dp1[f[u]];
			dp2[u]=dp2[f[u]];
		}
		ans=max(ans,dp1[u]);
	}
	printf("%d\n",ans);
	return 0;
}