#include <bits/stdc++.h>
using namespace std;
string s;
int pnt,maxn,le,app[10005];
int main()
{
	scanf("%d",&le);
	cin>>s;
	for(int i=0;i<le-1;i++)
		app[(s[i]-'A')+(s[i+1]-'A')*50]++;
	for(int i=0;i<=10000;i++)
		if(maxn<app[i])
			maxn=app[i],pnt=i;
	printf("%c%c",pnt%50+'A',pnt/50+'A');
	return 0;
}