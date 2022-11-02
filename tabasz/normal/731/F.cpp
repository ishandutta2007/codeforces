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

int T[200005], A[200005], n;
LL res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=1; i<=n; i++)
		cin>> T[i];
	sort(T+1, T+n+1);
	int tmp=0, ind=n;
	T[0]=-1000;
	for(int i=200001; i>0; i--)
	{
		while(T[ind]>=i)
		{
			tmp++;
			ind--;
		}
		A[i]=tmp;
	}
	int prev=-1;
	for(int i=1; i<=n; i++)
	{
		if(T[i]==prev)
			continue;
		prev=T[i];
		LL r=0;
		for(int j=T[i]; j<=200000; j+=T[i])
		{
			r+=(LL)T[i]*A[j];
			//printf("   %d %d\n", j, A[j]);
			if(A[j]==0)
				break;
		}
		res=max(res, r);
		//printf("%d: %d\n", i, r);
	}
	cout<< res << '\n';
	return 0;
}