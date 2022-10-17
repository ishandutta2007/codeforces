#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,x,y,dx,dy,k,mx,my,dm,z;
int main()
{
	cin>>n>>m>>x>>y>>k;
	while(k--)
	{
		cin>>dx>>dy;
		if(dx<0)
			mx=(x-1)/dx;
		else if(dx>0)
			mx=(n-x)/dx;
		if(dy<0)
			my=(y-1)/dy;
		else if(dy>0)
			my=(m-y)/dy;
		mx=abs(mx);
		my=abs(my);
		if(!dx)
			dm=my;
		else if(!dy)
			dm=mx;
		else
			dm=min(mx,my);
		x+=dm*dx;
		y+=dm*dy;
		z+=dm;
	}
	cout<<z;
	return 0;
}