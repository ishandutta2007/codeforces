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

int n, write=1, T[50005], P[32], A[50005];
vector<int> V[2000005], R, R2;
vector<PII> X;
map<int, int> M;

void add(int x, int ind)
{
	if(M[x]==0)
	{
		M[x]=write;
		write++;
		X.PB(MP(x, write-1));
	}
	V[M[x]].PB(ind);
}

bool good(int ind)
{
	int tmp=0, ind2=ind;
	R2.clear();
	while(ind>=0 && tmp<n)
	{
		for(int i=0; i<(int)V[X[ind].S].size(); i++)
		{
			if(A[V[X[ind].S][i]]!=ind2)
			{
				tmp++;
				A[V[X[ind].S][i]]=ind2;
				R2.PB(X[ind].F);
				break;
			}
		}
		ind--;
	}
	if(tmp==n)
		return true;
	return false;
}

int main()
{
	X.PB(MP(0, 0));
	P[0]=1;
	for(int i=1; i<32; i++)
		P[i]=P[i-1]*2;
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", T+i);
		int j=0;
		while(T[i]/P[j]>0)
		{
			add(T[i]/P[j], i);
			j++;
		}
	}
	sort(X.begin(), X.end());
	int st=0, en=X.size()-1, mid=(st+en)/2, r=1000000000;
	while(st<=en)
	{
		if(good(mid))
		{
			r=min(r, mid);
			R=R2;
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	for(int i=0; i<n; i++)
		printf("%d ", R[i]);
	printf("\n");
	return 0;
}