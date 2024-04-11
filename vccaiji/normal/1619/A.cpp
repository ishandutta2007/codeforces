#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int main()
{
int t;
scanf("%d",&t);
for(int i=1;i<=t;i++)
{
	scanf("%s",a);
	int l;
	for(int i=0;i<110;i++) 
	{
		if((a[i]<'a')||(a[i]>'z'))
		{
			l=i;
			break;
		}
	}
	if(l&1) printf("NO");
	else
	{
		bool r=true;
		for(int i=0;i<l/2;i++)
		 if(a[i]!=a[i+l/2])
		 {
		 	r=false;
		 	break;
		 }
		 if(r) printf("YES");
		 else printf("NO");
	}
 	if(i<t) printf("\n");
}
	return 0;
}