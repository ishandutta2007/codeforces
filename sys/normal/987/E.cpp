#include <bits/stdc++.h>
using namespace std;
int cnt,n,num[1000005],now[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		now[num[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(now[i]!=i) 
		{
			now[num[i]]=now[i];
			swap(num[i],num[now[i]]);
			now[i]=i;
			cnt++;
		}
	}
	if((3*n)%2==cnt%2) printf("Petr");
	else printf("Um_nik");
	return 0;
}