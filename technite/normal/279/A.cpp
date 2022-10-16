#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z=0;
	cin>>x>>y;
	if(y>x&&x>=-y) z = -2 + y*4;
	if(y<x&&x<=-y+1) z = -y*4;
	if(y<=x&&x>-y+1) z = -3 + x*4;
	if(y>=x&&x<-y) z = -1 - 4*x;
	cout<<z;
}