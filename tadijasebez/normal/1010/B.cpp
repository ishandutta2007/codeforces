#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int Ask(int y)
{
	printf("%i\n",y);
	fflush(stdout);
	int b;
	scanf("%i",&b);
	return b;
}
vector<bool> ok;
int cnt=0,n;
int Ask2(int y)
{
	printf("%i\n",y);
	fflush(stdout);
	int b;
	scanf("%i",&b);
	if(!ok[cnt%n]) b=-b;
	cnt++;
	return b;
}
int main()
{
	int m,i;
	scanf("%i %i",&m,&n);
	for(i=1;i<=n;i++)
	{
		int b=Ask(1);
		if(b==0) return 0;
		if(b==1) ok.pb(1);
		else ok.pb(0);
	}
	int top=m,bot=1,ans,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		int h=Ask2(mid);
		if(h==0) return 0;
		if(h==1) bot=mid+1,ans=mid;
		else top=mid-1;
	}
	Ask2(ans);
	return 0;
}