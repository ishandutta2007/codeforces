#include<bits/stdc++.h>
using namespace std;
const int N=105;
char a[N],b[N],c[N];
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a+1,b+1,c+1);
		n=strlen(a+1);
		int ok=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=c[i]&&b[i]!=c[i])
				ok=0;
		puts(ok?"YES":"NO");
	}
	return 0;
}