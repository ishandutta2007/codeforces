#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=26;
int n,q,a[M][N];
char s[N];
int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			a[j][i]=a[j][i-1];
		a[s[i]-'a'][i]++;	
	}
	while(q--)
	{
		int l,r,t=0;
		scanf("%d%d",&l,&r);
		for(int i=0;i<26;i++)
			t+=(i+1)*(a[i][r]-a[i][l-1]);
		printf("%d\n",t);
	}
	return 0;
}