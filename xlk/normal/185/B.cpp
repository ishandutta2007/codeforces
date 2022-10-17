#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double a,b,c,s,sp;
int main()
{
	cin>>s>>a>>b>>c;
	sp=a+b+c;
	if(a>0||b>0||c>0)
		printf("%.15f %.15f %.15f\n",a/sp*s,b/sp*s,c/sp*s);
	else
		printf("%.15f %.15f %.15f\n",0.0,0.0,0.0);
}