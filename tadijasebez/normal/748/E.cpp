#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
const int M=1e7+5;
int a[N];
ll cnt[M];
int main()
{
	int n,i;ll k;
	scanf("%i %lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	int ans=-1;i=1;int j=1e7;
	while(k>0)
	{
		int x=0;
		if(i<=n) x=a[i];
		while(j>x*2 && !cnt[j]) j--;
		if(!x && j==1) return 0*printf("-1\n");
		if(!j) return 0*printf("-1\n");
		if(j<=2*x) ans=x,i++,k--,cnt[x]++;
		else
		{
			cnt[j>>1]+=cnt[j];
			cnt[j+1>>1]+=cnt[j];
			k-=cnt[j];
			ans=j>>1;
			cnt[j]=0;
			j--;
		}
	}
	printf("%i\n",ans);
	return 0;
}