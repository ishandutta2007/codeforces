#include <bits/stdc++.h>
using namespace std;
int cnt,n,a[200005],maxi; 
bool cho[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		if(a[i]<=a[i-1]*2) cho[i]=true;
	cnt=1;
	for(int i=1;i<=n;i++)
		if(cho[i]) cnt++;
		else maxi=max(maxi,cnt),cnt=1;
	maxi=max(maxi,cnt);
	printf("%d",maxi);
	return 0;
}