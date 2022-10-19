#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],v[N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int x=1;x<(n+1)/2;x++)
	{
		if(n%x)
			continue;
		for(int i=0;i<x;i++)
			v[i]=1;
		for(int i=0;i<n;i++)
			if(!a[i])
				v[i%x]=0;
		for(int i=0;i<x;i++)
		{
			if(v[i])
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}