#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
void inf()
{
	puts("Infinite");
	exit(0);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==1)
		{
			if(a[i-1]==1)
				inf();
			if(a[i-1]==2)
				ans+=3;
			if(a[i-1]==3)
				ans+=4; 
		}
		if(a[i]==2)
		{
			if(a[i-1]==1)
				ans+=3;
			if(a[i-1]==2)
				inf();
			if(a[i-1]==3)
				inf(); 
		}
		if(a[i]==3)
		{
			if(a[i-1]==1)
				ans+=4;
			if(a[i-1]==2)
				inf();
			if(a[i-1]==3)
				inf(); 
		}
	}
	for(int i=2;i<=n;i++)
		if(a[i-2]==3&&a[i-1]==1&&a[i]==2)
			ans--;
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}