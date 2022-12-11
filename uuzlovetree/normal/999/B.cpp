#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
int n;
char s[maxn];
int main()
{
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)if(n%i==0)
	{
		for(int j=1;j<=(i+1)/2;++j)
		{
			int r=i-j+1;
			swap(s[j],s[r]);
		}
	}
	printf("%s\n",s+1);
	return 0;
}