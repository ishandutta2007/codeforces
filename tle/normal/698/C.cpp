#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
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
#define inf 1001001001
#define infll 1001001001001001001LL
#define FOR0(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR1(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define ld double
#define vi vector<int>
#define fi first
#define se second
#define RI(n) int (n); scanf("%d",&(n));
#define RI2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define RI3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR0(i,sz(t))s<<t[i]<<" ";return s; }
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define all(t) t.begin(),t.end()
#define FEACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS RI(testow)while(testow--)
#define FORZ(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define FORD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define ios0 ios_base::sync_with_stdio(0)
int n,K,id[233];
double p[2333],qwq[2333];
double dp[23][(1<<20)+2];
int main()
{
	scanf("%d%d",&n,&K);
	int nn=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",p+i);
		if(p[i]<1e-8); else id[nn++]=i;
	}
	K=min(K,nn);
	dp[0][0]=1;
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<(1<<nn);j++)
		{
        	if (__builtin_popcount(j)<i) continue;
			double gl=0;
			for(int s=0;s<nn;s++)
				if(j&(1<<s)) gl+=p[id[s]];
			if(fabs(gl-1)<1e-8) continue;
			for(int s=0;s<nn;s++)
			{
				if(j&(1<<s)) ;
				else dp[i+1][j^(1<<s)]+=dp[i][j]*p[id[s]]/(1-gl);
			}
		}
	}
	for(int j=0;j<(1<<nn);j++)
	{
		for(int s=0;s<nn;s++)
			if(j&(1<<s)) qwq[id[s]]+=dp[K][j];
	}
	for(int i=0;i<n;i++) printf("%.10lf ",qwq[i]);
}