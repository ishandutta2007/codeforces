#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=200050;
const int M=2*N;
const int inf=1e9+7;
int x[M],y[M],ls[M],rs[M],clock,root;
int min(int a, int b){ return a>b?b:a;}
void Build(int &c, int ss, int se)
{
	c=++clock;x[c]=inf;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qi, int val)
{
	if(ss==se){ x[c]=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	x[c]=min(x[ls[c]],x[rs[c]])+y[c];
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ y[c]+=val,x[c]+=val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=min(x[ls[c]],x[rs[c]])+y[c];
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+y[c];
}
set<pair<int,pair<int,int> > > ord;
set<pair<int,pair<int,int> > >::iterator it;
ll sol;
vector<pair<int,int> > p;
int main()
{
	int n,k,m,i,x,y;
	scanf("%i %i %i",&k,&n,&m);
	while(m--) scanf("%i %i",&x,&y),p.pb(mp(x,y));
	p.pb(mp(k,inf));
	sort(p.begin(),p.end());
	Build(root,0,N-1);
	int sz=n;int last=0;
	for(i=0;i<p.size();i++)
	{
		int time=p[i].first-last;
		sz-=time;
		//printf("T->%i %i\n",time,sz);
		if(sz<0)
		{
			for(it=ord.begin();it!=ord.end();)
			{
				pair<int,pair<int,int> > tmp=*it;
				it++;
				ord.erase(tmp);
				tmp.second.first=Get(root,0,N-1,tmp.second.second,i-1);
				if(sz+tmp.second.first<0)
				{
					//printf("->%i %i\n",tmp.second.first,sz+tmp.second.first);
					sz+=tmp.second.first;
					sol+=(ll)tmp.first*tmp.second.first;
					Set(root,0,N-1,tmp.second.second,i-1,-tmp.second.first);
				}
				else
				{
					//printf("->%i 0\n",-sz);
					sol-=(ll)tmp.first*sz;
					Set(root,0,N-1,tmp.second.second,i-1,sz);
					ord.insert(tmp);
					sz=0;
					break;
				}
			}
			if(sz<0) return printf("-1\n"),0;
		}
		Set(root,0,N-1,i,n-sz);
		ord.insert(mp(p[i].second,mp(n-sz,i)));
		last=p[i].first;
	}
	printf("%lld\n",sol);
	return 0;
}