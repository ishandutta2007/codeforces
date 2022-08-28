//CF 569C 
//WA on 5
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
const int m = 3e6;
int d[333333],sd;
bool pri(int x){
	if(x<=1)
		return false;
	int i;
	for(i=1;i<=sd&&(LL)d[i]*d[i]-x<=0;i=i+1)
		if(x%d[i]==0)
			return false;
	sd++;
	d[sd]=x;
	return true;
}
bool pal(int x){
	int a[11],i;
	i=0;
	while(x>0){
		i++;
		a[i]=x%10;
		x/=10;
	}
	x=i;
	for(i=1;i<=x/2;i=i+1)
		if(a[i]!=a[x+1-i])
			return false;
	return true;
}
int main()
{
	int p,q,i,ans,f,g;
	scanf("%d%d",&p,&q);
	sd=0;ans=0;
	f=0;
	g=0;
	for(i=1;i<=m;i=i+1){
		if(pri(i))
			f++;
		if(pal(i))
			g++;
		if((LL)f*q<=(LL)g*p)
			ans=i;
	}
	if(ans==0)
		printf("Palindromic tree is better than splay tree\n");
	else
		printf("%d",ans);
	return 0;
}