#include <bits/stdc++.h>
using namespace std;
int sgn(int x){ return x==0?0:x/abs(x);}
int main()
{
	int cnt[3]={0,0,0},n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		cnt[sgn(x)+1]++;
	}
	if(cnt[0]>=(n+1)/2) printf("-1\n");
	else if(cnt[2]>=(n+1)/2) printf("1\n");
	else printf("0\n");
	return 0;
}