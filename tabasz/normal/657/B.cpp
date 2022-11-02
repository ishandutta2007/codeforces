#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, res, kk;
int T[200005];
LL X[200005], k;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &kk);
	k=kk;
	for(int i=0; i<=n; i++)
		scanf("%d", T+i);
	LL tmp=0;
	for(int i=0; i<n; i++)
	{
		tmp+=T[i];
		if(max(tmp, -tmp)%2==1)
		{
			for(int j=i+1; j<n; j++)
				X[j]=-1000000000000000000;
			break;
		}
		tmp/=2;
		X[i+1]=tmp;
		//printf("%d: %d\n", i, X[i+1]);
	}
	tmp=0;
	for(int i=n; i>=0; i--)
	{
		tmp+=T[i];
		//printf("%d %d %d\n", i, tmp, T[i]);
		if(X[i]!=-1000000000000000000 && max((LL)T[i]-tmp-X[i], tmp+X[i]-(LL)T[i])<=k && tmp+X[i]!=0LL && (i!=n || (LL)T[i]-tmp-X[i]!=0))
		{
			res++;
			//printf("     %d %d %d\n", i, tmp, X[i-1]);
		}
		tmp*=2;
		//printf("tmp=%d, %d\n", tmp, k);
		if(max(tmp, -tmp)>50*k)
			break;
	}
	printf("%d\n", res);
	return 0;
}