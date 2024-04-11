#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int n,x;
char s[9];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		if(*s=='s')
		{
			long long z=0;
			for(int i=2;i<a.size();i+=5)
				z+=a[i];
			printf("%I64d\n",z);
		}
		else
		{
			scanf("%d",&x);
			if(*s=='a')
				a.insert(lower_bound(a.begin(),a.end(),x),x);
			else
				a.erase(lower_bound(a.begin(),a.end(),x));
		}
	}
	return 0;
}