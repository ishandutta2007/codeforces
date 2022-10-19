#include<bits/stdc++.h>
using namespace std;
char s[101];int a[100],b[100];
int main()
{
	int n,i,j,c=0,r=0;
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++)
		scanf("%d%d",b+i,a+i),c+=s[i]=='1';
	for(r=c,i=0;i<130;i++)
	{
		for(j=0;j<n;j++)
			if(a[j]==i)
				s[j]^=1,s[j]=='1'?c++:c--,a[j]+=b[j];
		if(c>r)
			r=c;
	}
	printf("%d\n",r);
	return 0; 
}