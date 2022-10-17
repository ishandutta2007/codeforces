#include<stdio.h>
#include<set>
int v[1000020],t;
long long i,j,n;
std::set<long long>s;
int main()
{
	for(i=2;i<=1000000;i++)
		if(!v[i])
		{
			s.insert(i*i);
			for(j=i*i;j<=1000000;j+=i)
				v[j]=1;
		}
	for(scanf("%d",&t);t--;puts(s.count(n)?"YES":"NO"))
		scanf("%I64d",&n);
}