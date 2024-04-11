#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		a=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'&&s[i%n+1]=='0')
				a++;
		printf("%d\n",a);
	}
	return 0;
}