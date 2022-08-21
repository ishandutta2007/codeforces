#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int n,k,s[55555][55],l[55555][55],r[55555][55],sz[55555];
struct cmp
{
bool operator () (int a,int b) {return l[a][1]<l[b][1];}
};
set<int,cmp> si;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
			scanf("%d",&s[i][j]),
			l[i][j]=r[i][j]=s[i][j];
	for(int i=1;i<=n;++i)
	{
		si.insert(i); sz[i]=1;
		while(1)
		{
			auto s=si.find(i);
			if(s!=si.begin())
			{
				--s; int g=*s,j;
				//l[g][1]<l[i][1]
				for(j=1;j<=k;++j)
					if(r[g][j]>l[i][j]) break;
				if(j<=k) //merge
				{
					si.erase(s); sz[i]+=sz[g];
					for(int j=1;j<=k;++j)
						l[i][j]=min(l[i][j],l[g][j]),
						r[i][j]=max(r[i][j],r[g][j]);
					continue;
				}
			}
			s=si.find(i);
			if((++s)!=si.end())
			{
				int g=*s,j;
				//l[g][1]>l[i][1]
				for(j=1;j<=k;++j)
					if(l[g][j]<r[i][j]) break;
				if(j<=k) //merge
				{
					si.erase(s); sz[i]+=sz[g];
					for(int j=1;j<=k;++j)
						l[i][j]=min(l[i][j],l[g][j]),
						r[i][j]=max(r[i][j],r[g][j]);
					continue;
				}
			}
			break;
		}
		printf("%d\n",sz[*(--si.end())]);
	}
}