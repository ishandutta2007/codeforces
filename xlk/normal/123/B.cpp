#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
long long a,b,x1,x2,y1,y2,t=200000000LL;
int main()
{
	cin>>a>>b>>x1>>y1>>x2>>y2;
	cout<<max(abs((x1+y1+t*a)/(2*a)-(x2+y2+t*a)/(2*a)),abs((x1-y1+t*b)/(2*b)-(x2-y2+t*b)/(2*b)));
	return 0;
}