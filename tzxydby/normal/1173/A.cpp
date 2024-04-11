#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int x,y,z;
	cin>>x>>y>>z;
	if(x>y+z)
		puts("+");
	else if(y>x+z)
		puts("-");
	else if(x==y&&z==0)
		puts("0");
	else
		puts("?");
	return 0;
}