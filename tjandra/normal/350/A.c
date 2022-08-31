#include<stdio.h>
typedef unsigned u;
int main()
{
	u mw,mr,Mr=0,w,r,n,T;
	scanf("%u%u",&r,&w);
	for(mw=mr=0xffffffffu;r--;mr>n?mr=n:0,Mr<n?Mr=n:0)scanf("%u",&n);
	while(w--)scanf("%u",&n),mw>n?mw=n:0;T=(mr<<=1)<Mr?Mr:mr;
	printf(T<mw?"%u\n":"-1\n",T);
	return 0;
}