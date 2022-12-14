#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
char t[N];int n,m,now,lst,siz;
int main()
{
	scanf("%s",t+1);n=strlen(t+1);
	for(int i=n;i;i--)if(t[i]=='a'){lst=i;break;}
	for(int i=1;i<=lst;i++)siz+=(t[i]!='a');
	if((n-lst-siz)&1)return puts(":("),0;
	m=lst+((n-lst-siz)>>1);int i,j;
	for(i=1,j=m+1;i<=m||j<=n;)
	{
		if(t[i]=='a'){i++;continue;}
		if(t[i]==t[j])i++,j++;
		else return puts(":("),0;
	}
	if(i==m+1&&j==n+1)
	{
		for(int i=1;i<=m;i++)printf("%c",t[i]);puts("");
	}else puts(":(");
}