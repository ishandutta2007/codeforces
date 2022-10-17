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
char ss[5000020];
int w[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[1000020],c,n,m;
int main()
{
	for(int i=1;i<=12;i++)
		w[i]+=w[i-1];
	scanf("%d %d",&n,&m);
	gets(ss);
	while(gets(ss))
	{
		int y,m,d,h,mm,s;
		sscanf(ss,"%d-%d-%d %d:%d:%d",&y,&m,&d,&h,&mm,&s);
		int sec=w[m-1]+d-1;
		sec*=86400;
		sec+=h*3600+mm*60+s;
		a[c++]=sec;
	}
	sort(a,a+c);
	int l=0;
	for(int i=0;i<c;i++)
	{
		while(a[i]-a[l]>=n)
			l++;
		if(i-l+1>=m)
		{
			int s=a[i]%60;
			int m=a[i]%3600/60;
			int h=a[i]%86400/3600;
			int d=a[i]/86400;
			int M=0;
			for(;w[M]<=d;M++)
				;
			d-=w[M-1];
			printf("2012-%02d-%02d %02d:%02d:%02d",M,d+1,h,m,s);
			return 0;
		}
	}
	puts("-1");
	return 0;
}