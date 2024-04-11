#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100050;
const int M=2*N;
const int H=10000;
const int inf=1e8;
vector<int> lucky;
bool Check(int x){ while(x){ if(x%10!=4 && x%10!=7) return 0;x/=10;}return 1;}
void FindLuckyNumbers(){ for(int i=1;i<H;i++) if(Check(i)) lucky.pb(i);}
struct Node
{
	int cnt,id,val;
	Node(){ cnt=1,id=0,val=0;}
	Node operator + (Node b) const
	{
		Node c;
		if(val>b.val)
		{
			c.val=b.val;
			c.id=b.id;
			c.cnt=b.cnt;
		}
		else if(val<b.val)
		{
			c.val=val;
			c.id=id;
			c.cnt=cnt;
		}
		else
		{
			c.val=val;
			c.id=id;
			c.cnt=cnt+b.cnt;
		}
		return c;
	}
	Node operator + (int x)
	{
		Node c;
		c.val=val+x;
		c.id=id;
		c.cnt=cnt;
		return c;
	}
} node[M];
int ls[M],rs[M],lzy[M],d[N],a[N],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c].val=d[a[ss]];node[c].id=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Push(int c, int ss, int se)
{
	if(lzy[c])
	{
		node[c].val+=lzy[c];
		if(ss!=se)
		{
			lzy[ls[c]]+=lzy[c];
			lzy[rs[c]]+=lzy[c];
		}
		lzy[c]=0;
	}
}
void Set(int c, int ss, int se, int qi, int x)
{
	Push(c,ss,se);
	if(ss==se){ node[c].val=x;node[c].id=ss;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	Push(ls[c],ss,mid);
	Push(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Add(int c, int ss, int se, int qs, int qe, int x)
{
	Push(c,ss,se);
	if(qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]+=x;Push(c,ss,se);return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	Push(c,ss,se);
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
struct BIT
{
	int sum[N];
	BIT(){}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	void Set(int l, int r, int f){ Set(l,f);Set(r+1,-f);}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
} Tree;
int main()
{
	FindLuckyNumbers();
	int i;
	for(i=1;i<=H;i++)
	{
		int j=lower_bound(lucky.begin(),lucky.end(),i)-lucky.begin();
		if(j==lucky.size()) d[i]=inf;
		else d[i]=lucky[j]-i;
	}
	//for(i=1;i<=20;i++) printf("%i ",d[i]);printf("\n");
	int n,q,l,r,k;char t[10];
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	while(q--)
	{
		scanf("%s %i %i",t+1,&l,&r);
		if(t[1]=='a')
		{
			scanf("%i",&k);
			Tree.Set(l,r,k);
			Add(root,1,n,l,r,-k);
			while(1)
			{
				Node tmp=Get(root,1,n,l,r);
				if(tmp.val>=0) break;
				int id=tmp.id;
				//printf("%i\n",Tree.Get(id)+a[id]);
				Set(root,1,n,id,d[Tree.Get(id)+a[id]]);
			}
		}
		else
		{
			Node tmp=Get(root,1,n,l,r);
			if(tmp.val==0) printf("%i\n",tmp.cnt);
			else printf("0\n");
		}
	}
	return 0;
}