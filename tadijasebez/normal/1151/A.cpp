#include <bits/stdc++.h>
using namespace std;
int Get(char a, char b)
{
	int x=a-'A';
	int y=b-'A';
	return min(abs(x-y),26-abs(x-y));
}
int main()
{
	int n;
	scanf("%i",&n);
	string s;
	cin>>s;
	int ans=1e9;
	for(int i=0;i<=n-4;i++)
	{
		int sum=Get(s[i],'A')+Get(s[i+1],'C')+Get(s[i+2],'T')+Get(s[i+3],'G');
		ans=min(ans,sum);
	}
	printf("%i\n",ans);
	return 0;
}