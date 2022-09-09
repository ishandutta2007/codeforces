#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
struct Node
{
	int ans_l,ans_r,ans;
	int mx,mn;
	void init(int x)
	{
		ans_l=-x;ans_r=-x,ans=0;
		mx=mn=x;
	}
	void upd(int x)
	{
		mx+=x;
		mn+=x;
		ans_l-=x;
		ans_r-=x;
	}
	/*int l,r,ans;
	int L,R,b;
	Node(){}
	void init(char c)
	{
		if(c=='(') r=1,l=0,ans=1,b=1;
		else l=1,r=0,ans=1,b=-1;
		L=l;R=r;
	}
	void Print()
	{
		printf("%i %i %i\n",l,r,ans);
	}*/
};
Node operator + (Node a, Node b)
{
	Node c;
	c.mx=max(a.mx,b.mx);
	c.mn=min(a.mn,b.mn);
	c.ans_l=max(a.ans_l,b.ans_l);
	c.ans_l=max(c.ans_l,b.mx-2*a.mn);
	c.ans_r=max(a.ans_r,b.ans_r);
	c.ans_r=max(c.ans_r,a.mx-2*b.mn);
	c.ans=max(a.ans,b.ans);
	c.ans=max(c.ans,a.ans_r+b.mx);
	c.ans=max(c.ans,b.ans_l+a.mx);
	return c;
    /*Node c;
    c.l=a.l+max(0,b.l-a.r);
    c.r=b.r+max(0,a.r-b.l);
    c.L=max(a.L+max(0,b.l-a.r),b.L);
    c.R=max(b.R+max(0,a.r-b.l),a.R);
    c.b=a.b+b.b;
    c.ans=max(a.ans+b.R,b.ans+a.L);
    c.ans=max(c.ans,a.L+b.R);
    //a.Print();
    //b.Print();
    //c.Print();
    //printf("\n");*/
    return c;
}
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
Node node[M];
int lzy[M];
void Set(int &c, int ss, int se, int qi, int ch)
{
	if(!c) c=++tsz;
	if(ss==se){ node[c].init(ch);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,ch);
	else Set(rs[c],mid+1,se,qi,ch);
	node[c]=node[ls[c]]+node[rs[c]];
	//printf("c:(%i %i) %i %i %i\n",ss,se,node[c].l,node[c].r,node[c].ans);
}
void push(int c)
{
	if(!lzy[c]) return;
	node[ls[c]].upd(lzy[c]);
	node[rs[c]].upd(lzy[c]);
	lzy[ls[c]]+=lzy[c];
	lzy[rs[c]]+=lzy[c];
	lzy[c]=0;
}
void Inc(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]+=f;node[c].upd(f);return;}
	push(c);
	int mid=ss+se>>1;
	Inc(ls[c],ss,mid,qs,qe,f);
	Inc(rs[c],mid+1,se,qs,qe,f);
	node[c]=node[ls[c]]+node[rs[c]];
}
char s[N];
int main()
{
	int n,q,i,x,y;
	scanf("%i %i",&n,&q);
	n=(n-1)*2;
	scanf("%s",s+1);
	int b=0;
	Set(root,0,n,0,b);
	for(i=1;i<=n;i++)
	{
		b+=s[i]=='('?1:-1;
		Set(root,0,n,i,b);
	}
	printf("%i\n",node[root].ans);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		swap(s[x],s[y]);
		//printf("%s\n",s+1);
		int f;
		if(s[x]=='(') f=1;
		else f=-1;
		Inc(root,0,n,x,n,f);
		Inc(root,0,n,y,n,-f);
		if(s[y]=='(') f=1;
		else f=-1;
		Inc(root,0,n,y,n,f);
		Inc(root,0,n,x,n,-f);

		//Set(root,1,n,x,s[x]);
		//Set(root,1,n,y,s[y]);
		printf("%i\n",node[root].ans);
	}
	return 0;
}