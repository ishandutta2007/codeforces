#include<bits/stdc++.h>
using namespace std;
char a[105];
int main()
{
	int n,i,s1=0,s2=0;
	scanf("%d%s",&n,a);
	for(i=1;i<n;i++)
		if(a[i]!=a[i-1])
		{
			if(a[i]=='S') s1++;
			else s2++;
		}
	cout<<(s2>s1?"YES":"NO");
	return 0;
}