#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int t,n,a[N],r;
char s[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int f1=1,f2=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='-')
				a[i]=0;
			if(s[i]=='>')
				a[i]=1,f2=0;
			if(s[i]=='<')
				a[i]=2,f1=0;
		}
		if(f1||f2)
		{
			printf("%d\n",n);
			continue;
		}
		r=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0||a[(i==1?n:i-1)]==0)
				r++;
		printf("%d\n",r);
	}
	return 0;
}