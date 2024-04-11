#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
ll a[N];
int main()
{
	int n,m,i,l,cnt=0,t,p,x;
	scanf("%i %i %i",&n,&m,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>l && (i==1 || a[i-1]<=l)) cnt++;
	}
	while(m--)
	{
		scanf("%i",&t);
		if(t==0) printf("%i\n",cnt);
		else
		{
			scanf("%i %i",&p,&x);
			if(a[p]>l) continue;
			a[p]+=x;
			if(a[p]>l)
			{
				cnt++;
				if(p!=1 && a[p-1]>l) cnt--;
				if(p!=n && a[p+1]>l) cnt--;
			}
		}
	}
	return 0;
}