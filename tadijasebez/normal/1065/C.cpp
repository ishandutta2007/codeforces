#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int h[N];
int main()
{
	int n,i,j,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&h[i]);
    sort(h+1,h+1+n);reverse(h+1,h+1+n);
    int ans=0;
    ll sum=0;
    j=0;
    for(i=N-1;i>=0;i--)
	{
		while(j<n && h[j+1]>=i) j++;
		sum+=j;
		//if(sum) printf("%i %lld\n",i,sum);
		if(j==n){ sum-=j;ans+=sum>0;break;}
		if(sum>k) ans++,sum=j;
	}
	printf("%i\n",ans);
	return 0;
}