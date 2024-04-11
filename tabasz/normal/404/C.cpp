#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

pair<int, int> T[1000001];
vector<pair<int, int> > W;
int A[1000001];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i]=MP(a, i);
	}
	sort(T, T+n);
	if(T[1].F==0 || T[0].F!=0)
	{
		printf("-1\n");
		return 0;
	}
	if(k==1)
	{
		if(n==2) printf("1\n1 2\n");
		else printf("-1\n");
		return 0;
	}
	int pop=0;
	for(int i=1; i<n; i++)
	{	
		if(T[i].F>T[i-1].F+1 || T[i].F==T[pop].F || pop>=i)
		{
			printf("-1\n");
			return 0;
		}
		while((T[pop].F+1)!=T[i].F) pop++;
		if(pop==i)
		{
			printf("-1\n");
			return 0;
		}
		W.PB(MP(T[pop].S, T[i].S));
		A[pop]++;
		A[i]++;
		if(A[pop]>=k) pop++;
	}
	printf("%d\n", (int)W.size());
	for(int i=0; i<W.size(); i++) printf("%d %d\n", W[i].F+1, W[i].S+1);
	return 0;
}