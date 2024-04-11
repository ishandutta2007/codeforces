#include<iostream>
#include<stdio.h>
long long x,y,t;
int F(long long x,long long y)
{
	return x<y?F(y,x):y&&(!F(x%y,y)||1-x/y%(y+1)%2);
}
int main()
{
	for(std::cin>>t;t--;)
		std::cin>>x>>y,puts(F(x,y)?"First":"Second");
}