#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int M=2*N;
int a[N],k[N];
ll sum[N],ssm[N];
int ls[M],rs[M],tsz,root;
ll val[M],lzy[M];
bool has[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;has[c]=0;
	if(ss==se){ val[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	val[c]=val[ls[c]]+val[rs[c]];
}
void mdy(int c, int ss, int se, ll x)
{
	has[c]=1;lzy[c]=x;
	val[c]=(se-ss+1)*x+ssm[se]-ssm[ss-1];
}
void push(int c, int ss, int se)
{
	if(!has[c]) return;
	int mid=ss+se>>1;
	mdy(ls[c],ss,mid,lzy[c]);
	mdy(rs[c],mid+1,se,lzy[c]);
	has[c]=0;
}
void Add(int c, int ss, int se, int qs, int qe, ll x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ mdy(c,ss,se,x);return;}
	push(c,ss,se);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	val[c]=val[ls[c]]+val[rs[c]];
}
void Set(int c, int ss, int se, int qi, ll x)
{
	if(ss==se){ val[c]=x;return;}
	push(c,ss,se);
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	val[c]=val[ls[c]]+val[rs[c]];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return val[c];
	push(c,ss,se);
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
set<pair<int,int>> seg;
void Split(int x)
{
	auto it=seg.lower_bound({x+1,0});
	it--;
	int l=it->first,r=it->second;
	seg.erase(it);
	if(l!=x) seg.insert({l,x-1});
	seg.insert({x,r});
}
int main()
{
	int n,q,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++) scanf("%i",&k[i]);
	for(i=2;i<=n;i++) sum[i]=sum[i-1]+k[i-1];
	for(i=2;i<=n;i++) ssm[i]=ssm[i-1]+sum[i];
	Build(root,1,n);
	for(i=1;i<=n;i++) seg.insert({i,i});
	scanf("%i",&q);
	char t;int l,r,x;
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='+')
		{
            scanf("%i %i",&i,&x);
            ll A=Get(root,1,n,i,i);
            A+=x;Set(root,1,n,i,A);
            A-=sum[i];
            Split(i);
            Split(i+1);
			int l=i+1,r=i;
			auto it=seg.lower_bound({i+1,0});
			auto it1=it;
			while(it!=seg.end())
			{
				int j=it->first;
				ll B=Get(root,1,n,j,j);
				if(B<A+sum[j])
				{
					r=it->second;
					it++;
				}
				else break;
			}
			if(l<=r)
			{
				seg.erase(it1,it);
				seg.insert({l,r});
			}
			Add(root,1,n,l,r,A);
		}
		else
		{
			scanf("%i %i",&l,&r);
			printf("%lld\n",Get(root,1,n,l,r));
		}
	}
	return 0;
}