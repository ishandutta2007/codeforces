#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buffer_size=1e5+5;
	char buf[buffer_size],*S,*T;
	bool flag_EOF;
	inline char read_char()
	{
	    if(S==T)
			T=(S=buf)+fread(buf,1,buffer_size,stdin);
	    return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
	    int flag=1;
	    char c=read_char();
	    while(c<'0'||c>'9')
	    {
	        if(c==EOF)
	        {
	            flag_EOF=true;
	            return 0;
	        }
	        flag=(c=='-'?-1:1);
	        c=read_char();
	    }
	    int x=0;
	    while(c>='0'&&c<='9')
	    {
	        x=x*10+(c^48);
	        c=read_char();
	    }
	    return x*flag;
	}
	char st[13];
	int _top;
	void Write(int x)
	{
		if(!x)
		{
			putchar('0');
			return;
		}
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=5e5+5;
char s[max_n];
struct node
{
	int len,ll,lr,llr,lrl,rl,rr,rlr,rrl,mlr,mrl;
	bool lazy;
	inline node(char op='<')
	{
		len=1;
		if(op=='<')
			ll=llr=lrl=rl=rlr=rrl=mlr=mrl=1,lr=rr=0;
		else
			lr=llr=lrl=rr=rlr=rrl=mlr=mrl=1,ll=rl=0;
		lazy=false;
	}
	inline void clear()
	{
		len=ll=lr=llr=lrl=rl=rr=rlr=rrl=mlr=mrl=0;
		lazy=false;
	}
//	inline void print()
//	{
//		printf("len=%d ll=%d lr=%d llr=%d lrl=%d rl=%d rr=%d rlr=%d rrl=%d mlr=%d mrl=%d\n",len,ll,lr,llr,lrl,rl,rr,rlr,rrl,mlr,mrl);
//	}
	inline void inverse()
	{
		swap(ll,lr);
		swap(llr,lrl);
		swap(rl,rr);
		swap(rlr,rrl);
		swap(mlr,mrl);
	}
}tree[max_n<<2];
inline node operator + (const node &a,const node &b)
{
	static node res;
	res.len=a.len+b.len;
	res.ll=a.ll+(a.ll==a.len?b.ll:0);
	res.lr=a.lr+(a.lr==a.len?b.lr:0);
	res.llr=max(a.llr+(a.llr==a.len?b.lr:0),a.ll+(a.ll==a.len?b.llr:0));
	res.lrl=max(a.lrl+(a.lrl==a.len?b.ll:0),a.lr+(a.lr==a.len?b.lrl:0));
	res.rl=b.rl+(b.rl==b.len?a.rl:0);
	res.rr=b.rr+(b.rr==b.len?a.rr:0);
	res.rlr=max(b.rlr+(b.rlr==b.len?a.rl:0),b.rr+(b.rr==b.len?a.rlr:0));
	res.rrl=max(b.rrl+(b.rrl==b.len?a.rr:0),b.rl+(b.rl==b.len?a.rrl:0));
	res.mlr=max(max(a.mlr,b.mlr),max(a.rlr+b.lr,a.rl+b.llr));
	res.mrl=max(max(a.mrl,b.mrl),max(a.rrl+b.ll,a.rr+b.lrl));
	return res;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tree[p]=node(s[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
inline void push_down(int p)
{
	tree[p<<1].inverse();
	tree[p<<1|1].inverse();
	tree[p<<1].lazy^=1;
	tree[p<<1|1].lazy^=1;
	tree[p].lazy=false;
}
void modify(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		tree[p].inverse();
		tree[p].lazy^=1;
		return;
	}
	if(tree[p].lazy)
		push_down(p);
	int mid=(l+r)>>1;
	if(a<=mid)
		modify(p<<1,l,mid,a,b);
	if(b>mid)
		modify(p<<1|1,mid+1,r,a,b);
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
node res;
void query(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
//		printf("l=%d r=%d\n",l,r);
//		tree[p].print();
		res=res+tree[p];
//		res.print();
		return;
	}
	if(tree[p].lazy)
		push_down(p);
	int mid=(l+r)>>1;
	if(a<=mid)
		query(p<<1,l,mid,a,b);
	if(b>mid)
		query(p<<1|1,mid+1,r,a,b);
}
int main()
{
	int n,q;
	scanf("%d%d%s",&n,&q,s+1);
	build(1,1,n);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		modify(1,1,n,l,r);
		res.clear();
		query(1,1,n,l,r);
		printf("%d\n",res.mrl);
	}
	return 0;
}