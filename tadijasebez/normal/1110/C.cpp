#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	map<int,int> ans;
	/*for(int i=25;i<=25;i++)
	{
		int x=(1<<i)-1;
		for(int j=1;j<x;j++)
		{
			ans[x]=max(ans[x],__gcd(x^j,x&j));
		}
		printf("ans[%i]=%i\n",x,ans[x]);
	}*/
	ans[3]=1;
	ans[7]=1;
	ans[15]=5;
	ans[31]=1;
	ans[63]=21;
	ans[127]=1;
	ans[255]=85;
	ans[511]=73;
	ans[1023]=341;
	ans[2047]=89;
	ans[4095]=1365;
	ans[8191]=1;
	ans[16383]=5461;
	ans[32767]=4681;
	ans[65535]=21845;
	ans[131071]=1;
	ans[262143]=87381;
	ans[524287]=1;
	ans[1048575]=349525;
	ans[2097151]=299593;
	ans[4194303]=1398101;
	ans[8388607]=178481;
	ans[16777215]=5592405;
	ans[33554431]=1082401;
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n;
		scanf("%i",&n);
		int sz=1;
		while(sz<=n) sz*=2;
		if(sz-1==n)
		{
			//printf("%i\n",1);
			printf("%i\n",ans[n]);
		}
		else printf("%i\n",sz-1);
	}
	return 0;
}