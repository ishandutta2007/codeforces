#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double s=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		s+=1.0/i;
	printf("%.12lf",s);
	return 0;
}