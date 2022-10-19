#include<bits/stdc++.h>
using namespace std;
int main()
{
	char x,xx;
	char y,yy;
	cin>>x>>y;
	for(int i=0;i<5;i++)
	{
		cin>>xx>>yy;
		if(x==xx||y==yy)
		{
			puts("YES");
			return 0;
		}
	}	
	puts("NO");
	return 0;
}