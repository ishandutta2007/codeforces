#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,c[N];
char a[N];
set<long long>s;
long long x;
void out(long long x)
{
	for(int i=n;i>=1;i--)
		c[i]=x%2,x/=2;
	for(int i=1;i<=n;i++)
		printf("%d",c[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,a+1);
		x=0;
		for(int i=1;i<=n;i++)
			x=x*2+'1'-a[i];
		s.clear();
		s.insert(x);
		for(int i=n+1;i<2*n;i++)
		{
			x=x*2%(1LL<<n)+'1'-a[i];
			s.insert(x);
		}
		for(long long i=0;;i++)
		{
			if(!s.count(i))
			{
				out(i);
				break;
			}
		}
				
	}
	return 0;
}