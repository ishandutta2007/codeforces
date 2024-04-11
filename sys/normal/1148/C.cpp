#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,a[Maxn],pos[Maxn];
int cnt,x[5*Maxn],y[5*Maxn];
void work(int now)
{
	if(now==n)
	{
		if(a[now]<=n/2)
		{
			cnt++;
			x[cnt]=n;
			y[cnt]=a[n];
			swap(pos[a[n]],pos[a[a[n]]]);
			swap(a[n],a[a[n]]);
		}
		else
		{
			cnt++;
			x[cnt]=n;
			y[cnt]=1;
			swap(pos[a[n]],pos[a[1]]);
			swap(a[n],a[1]);
			work(1);
		}
	}
	else
	{
		if(a[now]>n/2)
		{
			cnt++;
			x[cnt]=1;
			y[cnt]=a[1];
			swap(pos[a[1]],pos[a[a[1]]]);
			swap(a[1],a[a[1]]);
		}
		else
		{
			cnt++;
			x[cnt]=n;
			y[cnt]=1;
			swap(pos[a[n]],pos[a[1]]);
			swap(a[n],a[1]);
			work(n);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(pos[i]<=n/2) 
		{
			cnt++;
			x[cnt]=pos[i];
			y[cnt]=n;
			swap(a[n],a[pos[i]]);
			swap(pos[a[n]],pos[a[pos[i]]]);
			work(n);
		}
		else
		{
			cnt++;
			x[cnt]=pos[i];
			y[cnt]=1;
			swap(a[1],a[pos[i]]);
			swap(pos[a[pos[i]]],pos[a[1]]);
			work(1);
		}
	}
	if(a[1]==n)
	{
		cnt++;
		x[cnt]=n;
		y[cnt]=1;
		swap(a[1],a[n]);
	}
 	for(int i=1;i<=n;i++)
		if(a[i]!=i) 0/0;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}