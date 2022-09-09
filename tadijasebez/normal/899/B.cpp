#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v,t;
int a[100];
bool Sub(int j, int n)
{
	for(int i=j;i<j+n;i++)
	{
		if(a[i-j+1]!=t[i]) return 0;
	}
	return 1;
}
int main()
{
	t.push_back(31);
	t.push_back(28);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);

	t.push_back(31);
	t.push_back(28);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);

	t.push_back(31);
	t.push_back(29);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);

	t.push_back(31);
	t.push_back(28);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);

	t.push_back(31);
	t.push_back(28);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);

	t.push_back(31);
	t.push_back(28);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	t.push_back(30);
	t.push_back(31);
	int n,i,m=0,k=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==29) m=i;
		if(a[i]==28) k=i;
	}
	for(i=0;i<t.size()-n;i++)
	{
		if(Sub(i,n)) return printf("YES\n"),0;
	}
	printf("NO\n");
	/*if(m)
	{
		for(i=1;i<=n;i++)
		{
			if(t[m-i+25]!=a[i]) return printf("NO\n"),0;
		}
		printf("YES\n");
	}
	else if(k)
	{
		for(i=1;i<=n;i++)
		{
			if(t[k-i+49]!=a[i]) return printf("NO\n"),0;
		}
		printf("YES\n");
	}
	else if(n>=12) return printf("NO\n"),0;
	else
	{
		if(a[1]==31 && a[2]==31)
		{
			for(i=1;i<=n;i++)
			{
				if(t[i+5]!=a[i]) return printf("NO\n"),0;
			}
			printf("YES\n");
		}
	}*/
	return 0;
}