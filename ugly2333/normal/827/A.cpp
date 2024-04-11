// CF 827A
#pragma comment(linker, "/STACK:102400000,102400000") 
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
char s[2222222],c[1111111];
int a[2222222];
int upd(int x,int y,int l){
	if(a[x]>=y+l)
		return a[x];
	s[a[x]]=c[a[x]-y];
	a[x]=upd(a[a[x]+1],y,l);
	return a[x];
}
int main()
{
	int n,i,l,j,k,x,o,p;
	for(i=0;i<=2e6+5;i=i+1)
		a[i]=i;
	scanf("%d",&n);
	p=0;
	for(i=1;i<=n;i=i+1){
		scanf("%s%d",&c,&k);
		l=strlen(c);
		//cout<<l<<a[0]<<endl;
		for(j=1;j<=k;j=j+1){
			scanf("%d",&x);
			x--;
			upd(x,x,l);
			p=max(p,x+l);
		}
	}
	for(i=0;i<p;i=i+1){
		if(!s[i])
			printf("a");
		else
			printf("%c",s[i]);
		//cout<<a[i]<<endl;
	}
	printf("\n");
	return 0;
}