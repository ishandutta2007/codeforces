#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",x);
#define print(x) printf("%d ",x);
const int inf=0x3fffffff;
const double pi=acos(-1.);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int l;
long long z=-1;
char c[1020];
int to(int s,int e)
{
	if(s==e)
		return -0xfffffff;
	if(c[s]=='0'&&s+1!=e)
		return -0xfffffff;
	if(s+1==e&&c[s]=='0')
		return 0;
	if(e-s>7)
		return -0xfffffff;
	int re=0;
	for(int i=s;i<e;i++)
		re=re*10+c[i]-'0';
	if(re<=1000000)
		return re;
	return -0xfffffff;
}
int main()
{
	scanf("%s",c);
	l=strlen(c);
	for(int i=0;i<l;i++)
		for(int j=i;j<l;j++)
			z=max(z,(long long)to(0,i)+to(i,j)+to(j,l));	
	cout<<z;
	return 0;
}