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
#define SZ(x) ((int)((x).size()))
#define fe first
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
int n;
char s[233][233];
#define YES {puts("Yes"); exit(0);}
#define NO {puts("No"); exit(0);}
bool chk(int x1,int y1,int x2,int y2)
{
	if(x1>=x2) return 0;
	if(y1>=y2) return 0;
	if(x1<0) return 0;
	if(y1<0) return 0;
	if(x2<0) return 0;
	if(y2<0) return 0;
	if(x1>n+1) return 0;
	if(y1>n+1) return 0;
	if(x2>n+1) return 0;
	if(y2>n+1) return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int ans=0;
			if(x1<i&&i<x2&&y1<j&&j<y2) ans=4;
			else if((x1<i&&i<x2&&(j==y1||j==y2))
			||(y1<j&&j<y2&&(i==x1||i==x2))) ans=2;
			else if((i==x1||i==x2)&&(j==y1||j==y2)) ans=1;
			else ans=0;
			if(s[i][j]!=ans+'0') return 0;
		}
	}
	return 1;
}
bool chk_(int x1,int y1,int x2,int y2)
{
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	return chk(x1,y1,x2,y2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	vector<pii> vpii;
	FOR1(x1,n)
	{
		FOR1(y1,n)
		{
			if(s[x1][y1]=='1') vpii.push_back(mp(x1,y1));
		}
	}
	if(vpii.size()>4) NO
	if(vpii.size()==3) NO
	if(vpii.size()==2) NO
	if(vpii.size()==4)
	{
		sort(vpii.begin(),vpii.end());
		if(!chk(vpii[0].fe,vpii[0].se,vpii[3].fe,vpii[3].se)) NO
		else YES
	}
	else if(vpii.size()==1)
	{
		if(chk_(vpii[0].fe,vpii[0].se,0,0)) YES
		if(chk_(vpii[0].fe,vpii[0].se,0,n+1)) YES
		if(chk_(vpii[0].fe,vpii[0].se,n+1,0)) YES
		if(chk_(vpii[0].fe,vpii[0].se,n+1,n+1)) YES
		NO
	}
	else
	{
		if(chk(0,0,n+1,n+1)) YES
		NO
	}
}