#include<cstdio>
#include<algorithm>
using namespace std;
#define F first
#define S second
#define MP make_pair

pair<int, int> T[300003], W[300003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i]=MP(a, i);
	}
	sort(T, T+n);
	int li=1;
	for(int i=0; i<n; i++)
	{
		if(T[i].F>li) li=T[i].F;
		W[i]=MP(T[i].S, li);
		li++;
	}
	sort(W, W+n);
	for(int i=0; i<n; i++) printf("%d ", W[i].S);
	return 0;
}