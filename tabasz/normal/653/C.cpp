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

int n, tmp, fir=1000000, res;
int T[150005];
bool B[150005];

void check(int ind)
{
	if(ind>0 && ind%2==1)
	{
		if(T[ind]>T[ind-1] && T[ind]>T[ind+1] && B[ind]==0)
		{
			B[ind]=1;
			tmp--;
		}
		else if((T[ind]<=T[ind-1] || T[ind]<=T[ind+1]) && B[ind]==1)
		{
			B[ind]=0;
			tmp++;
		}
	}
}

void go(int ind, int ind2)
{
	//printf("%d\n", ind);
	for(int i=0; i<n; i++)
	{
		if(i==ind || i==ind2)
			continue;
		swap(T[i], T[ind]);
		check(i-1);
		check(i);
		check(i+1);
		check(ind-1);
		check(ind);
		check(ind+1);
		if(tmp==0)
			res++;
		swap(T[i], T[ind]);
		check(i-1);
		check(i);
		check(i+1);
		check(ind-1);
		check(ind);
		check(ind+1);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", T+i);
	for(int i=1; i<n; i+=2)
	{
		if(T[i]<=T[i-1] || T[i]<=T[i+1])
		{
			fir=min(fir, i);
			tmp++;
		}
		else
			B[i]=1;
	}
	go(fir, fir-1);
	go(fir-1, fir+1);
	go(fir+1, fir);
	printf("%d\n", res);
	return 0;
}