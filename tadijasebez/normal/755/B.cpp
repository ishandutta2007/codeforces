#include <stdio.h>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
string x;
map<string,bool> used;
int t1,t2,tt;
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	t1=n,t2=m;
	while(n--) cin >> x,used[x]=true;
	while(m--) cin >> x,tt+=used[x],t1-=used[x],t2-=used[x];
	if(tt%2==0)
	{
		if(t1>t2) printf("YES\n");
		else printf("NO\n");
	}
	else
	{
		if(t1>=t2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}