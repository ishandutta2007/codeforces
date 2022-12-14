#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 100005
int f[N],num[26],n,k,ans;char s[N];
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'A';
		num[x]++;
		f[num[x]]|=(1<<x);
	}
	for(int i=1;i<=n;i++)
	{
		int xx=0;
		for(int j=0;j<26;j++)
			if(f[i]&(1<<j))xx++;
		if(xx>=k)ans=k*i;
	}printf("%d\n",ans);
}