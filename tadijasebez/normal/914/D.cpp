#include <stdio.h>
#include <vector>
using namespace std;
const int N=500050;
const int M=2*N;
struct Node
{
	int x;
	Node *ls,*rs;
};
Node root;
vector<Node*> ans;
int gcd(int x, int y){ return y?gcd(y,x%y):x;}
int a[N];
void Build(Node *c, int ss, int se)
{
	if(ss==se){ c->ls=NULL;c->rs=NULL;c->x=a[ss];return;}
	int mid=ss+se>>1;
	Node *tmp=new Node;
	c->ls=tmp;
	tmp=new Node;
	c->rs=tmp;
	Build(c->ls,ss,mid);
	Build(c->rs,mid+1,se);
	c->x=gcd(c->ls->x,c->rs->x);
}
void Update(Node *c, int ss, int se, int qi, int val)
{
	if(ss==se){ c->x=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Update(c->ls,ss,mid,qi,val);
	else Update(c->rs,mid+1,se,qi,val);
	c->x=gcd(c->ls->x,c->rs->x);
}
void Take(Node *c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ ans.push_back(c);return;}
	int mid=ss+se>>1;
	Take(c->ls,ss,mid,qs,qe);
	Take(c->rs,mid+1,se,qs,qe);
}
int main()
{
	int n,q,i,l,r,t,p,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(&root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&l,&r,&x);
			ans.clear();
			Take(&root,1,n,l,r);
			Node *bad;
			int cnt=0;
			for(i=0;i<ans.size();i++)
			{
				if(ans[i]->x%x) bad=ans[i],cnt++;
			}
			if(cnt==0){ printf("YES\n");continue;}
			if(cnt>1){ printf("NO\n");continue;}
			while(bad->ls!=NULL)
			{
				if(bad->ls->x%x && bad->rs->x%x) break;
				if(bad->ls->x%x) bad=bad->ls;
				else bad=bad->rs;
			}
			if(bad->ls==NULL) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			scanf("%i %i",&p,&x);
			Update(&root,1,n,p,x);
		}
	}
	return 0;
}