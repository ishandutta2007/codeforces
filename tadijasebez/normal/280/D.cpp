#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=2*N;
const int K=21;
const int inf=1e9+7;
struct seg
{
	int sum,l,r;
	seg(){}
	seg(int x, int i):sum(x),l(i),r(i){}
	seg(int x, int a, int b):sum(x),l(a),r(b){}
};
bool operator > (seg a, seg b){ return a.sum>b.sum;}
seg operator + (seg a, seg b){ return seg(a.sum+b.sum,a.l,b.r);}
seg max(seg a, seg b){ return a>b?a:b;}
seg min(seg a, seg b){ return a>b?b:a;}
struct Node
{
	seg best[2][2],ans[2],sum;
	Node(){}
	void init(int x, int i)
	{
		best[0][0]=max(seg(x,i),seg(0,i,i-1));
		best[1][0]=max(seg(x,i),seg(0,i+1,i));
		best[0][1]=min(seg(x,i),seg(0,i,i-1));
		best[1][1]=min(seg(x,i),seg(0,i+1,i));
		ans[0]=max(seg(x,i),seg(0,i,i-1));
		ans[1]=min(seg(x,i),seg(0,i,i-1));
		sum=seg(x,i);
	}
	void Flip()
	{
		sum.sum*=-1;
		swap(ans[0],ans[1]);
		ans[0].sum*=-1;
		ans[1].sum*=-1;
		swap(best[0][0],best[0][1]);
		best[0][0].sum*=-1;
		best[0][1].sum*=-1;
		swap(best[1][0],best[1][1]);
		best[1][0].sum*=-1;
		best[1][1].sum*=-1;
	}
};
Node operator + (Node a, Node b)
{
	Node c;
	c.ans[0]=max(a.ans[0],b.ans[0]);
	c.ans[0]=max(c.ans[0],a.best[1][0]+b.best[0][0]);
	c.ans[1]=min(a.ans[1],b.ans[1]);
	c.ans[1]=min(c.ans[1],a.best[1][1]+b.best[0][1]);
	c.sum=a.sum+b.sum;
	c.best[0][0]=max(a.best[0][0],a.sum+b.best[0][0]);
	c.best[0][1]=min(a.best[0][1],a.sum+b.best[0][1]);
	c.best[1][0]=max(b.best[1][0],a.best[1][0]+b.sum);
	c.best[1][1]=min(b.best[1][1],a.best[1][1]+b.sum);
	return c;
}
int ls[M],rs[M],tsz,root,lzy[M],a[N];
Node node[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=0;
	if(ss==se){ node[c].init(a[ss],ss);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void push(int c)
{
	if(!lzy[c]) return;
	node[ls[c]].Flip();
	node[rs[c]].Flip();
	lzy[ls[c]]^=1;
	lzy[rs[c]]^=1;
	lzy[c]=0;
}
void Flip(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]^=1;node[c].Flip();return;}
	push(c);
	int mid=ss+se>>1;
	Flip(ls[c],ss,mid,qs,qe);
	Flip(rs[c],mid+1,se,qs,qe);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int val)
{
	if(ss==se){ node[c].init(val,ss);return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	push(c);
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,q,i,t,l,r,k,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==0) scanf("%i %i",&i,&x),Set(root,1,n,i,x);
		else
		{
			scanf("%i %i %i",&l,&r,&k);
			vector<pair<int,int>> fl;
			int ans=0;
			while(k--)
			{
                Node tmp=Get(root,1,n,l,r);
                ans+=tmp.ans[0].sum;
                fl.push_back({tmp.ans[0].l,tmp.ans[0].r});
                Flip(root,1,n,tmp.ans[0].l,tmp.ans[0].r);
                //printf("%i (%i %i)\n",tmp.ans[0].sum,tmp.ans[0].l,tmp.ans[0].r);
			}
			for(auto p:fl) Flip(root,1,n,p.first,p.second);
			printf("%i\n",ans);
		}
	}
	return 0;
}