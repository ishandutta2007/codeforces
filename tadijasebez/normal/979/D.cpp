#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
const int N=100050;
const int H=1200050;
const int M=60000000;
const int K=2*N;
const int S=1;
int go[M][2],tsz1;
map<int,int> rt[K];
void Add(int &c, int lvl, int x)
{
	if(!c) c=++tsz1;
	if(lvl==-1) return;
	Add(go[c][(x>>lvl)&1],lvl-1,x);
}
int Get(int c, int lvl, int x)
{
	if(!c || lvl==-1) return 0;
	int g=((x>>lvl)&1)^1;
	if(go[c][g]) return (1<<lvl)+Get(go[c][g],lvl-1,x);
	else return Get(go[c][g^1],lvl-1,x);
}
void Set(int qi)
{
	for(int j=qi;j<N;j+=j&-j)
	{
		for(int i=1;i*i<=qi;i++)
		{
			if(i>S) break;
			if(qi%i) continue;
			Add(rt[j][i],16,qi);
			if(i*i!=qi) Add(rt[j][qi/i],16,qi);
		}
	}
}
int max(int a, int b){ return a>b?a:b;}
int GetSol(int qi, int x, int k)
{
	int ret=-1;
	for(int j=qi;j;j-=j&-j)
	{
		if(rt[j][k])
		{
			ret=max(ret,Get(rt[j][k],16,x));
		}
	}
	return ret;
}
/*int ls[K],rs[K],root,tsz;
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++tsz;
	for(int i=1;i*i<=qi;i++)
	{
		if(qi%i) continue;
		Add(rt[c][i],16,qi);
		if(i*i!=qi) Add(rt[c][qi/i],16,qi);
	}
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe, int x, int k)
{
	if(!c || ss>qe || qs>se) return -1;
	if(qs<=ss && qe>=se)
	{
		if(!rt[c][k]) return -1;
		return Get(rt[c][k],16,x);
	}
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe,x,k),Get(rs[c],mid+1,se,qs,qe,x,k));
}*/
bool was[N];
int main()
{
	int q,i,t,x,s,k;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&t,&x);
		if(t==1)
		{
			if(was[x]) continue;
			was[x]=1;
			Set(x);
		}
		else
		{
			scanf("%i %i",&k,&s);
			if(k<=S)
			{
				if(x%k || s<=x)
				{
					printf("-1\n");
					continue;
				}
				int qs=1,qe=s-x;
				int sol=GetSol(qe,x,k);
				if(sol==-1)
				{
					printf("-1\n");
					continue;
				}
				int y=x^sol;
				if(y>0) printf("%i\n",y);
				else printf("-1\n");
			}
			else
			{
				int sol=-1;
				for(i=k;i+x<=s;i+=k)
				{
					if(was[i]) sol=max(sol,x^i);
				}
				if(x%k) sol=-1;
				if(sol==-1) printf("%i\n",sol);
				else printf("%i\n",x^sol);
			}
		}
	}
	return 0;
}