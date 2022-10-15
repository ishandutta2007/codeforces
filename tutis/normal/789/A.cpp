#include <bits/stdc++.h>
#define INF 50e20
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t n, k;
	cin>>n>>k;
	int64_t K=0;
	int64_t w;
	for (int64_t i = 0; i < n; ++i)
	{
		cin>>w;
		int64_t x=w/k;
		K+=x;
		w-=x*k;
		if(w!=0)
			K++;
	}
	if(K%2==1)
		K++;
	cout<<K/2;
	return 0;
}