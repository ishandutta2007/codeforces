#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n,z,a[200001];
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&z);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	int pos=1,sum=0;
	for (int i = 0; i < n; ++i)
	{
		while(a[pos]-a[i]<z&&pos<n)
		{
			pos++;
		}
		if (pos==n)
		{
			goto end;
		}
		sum++;
		pos++;
	}
	end:;
	printf("%d\n", std::min(sum,n/2));
	return 0;
}