#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int n,s,x,y,mc=-1;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		x+=y/100;
		y%=100;
		if(x*100+y<=s*100) mc=max(mc,(100-y)%100);
	}
	cout<<mc;
}