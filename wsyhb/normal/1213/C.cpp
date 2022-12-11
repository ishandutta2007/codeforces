#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15][15],l[15],s[15];
int main()
{
	for(int i=0;i<=9;i++)
	{
		a[i][++l[i]]=i;
		s[i]=i;
		while(a[i][l[i]])
		{
			a[i][l[i]+1]=(a[i][l[i]]+i)%10;
			l[i]++;
			s[i]+=a[i][l[i]];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		ll x=n/m;
		ll s1=x/l[m%10],s2=x%l[m%10],ans=0;
		for(int i=1;i<=s2;i++) ans+=a[m%10][i];
		printf("%lld\n",ans+s1*s[m%10]);
	}
	return 0;
}