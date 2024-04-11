#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char s[N],t[N];
int n,m;
void sol()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<m;i++)
	{
		if(t[m-i+1]!=s[n-i+1])
		{
			puts("NO");
			return;
		}	
	}
	for(int i=1;i<=n-m+1;i++)
	{
		if(s[i]==t[1])
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}