#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%i",&q);
	while(q--)
	{
		int n;
		scanf("%i",&n);
		vector<int> b(n);
		for(int &i:b) scanf("%i",&i);
		int mn=b.back(),ans=0;
		for(;b.size();b.pop_back()) mn=min(mn,b.back()),ans+=mn!=b.back();
		printf("%i\n",ans);
	}
	return 0;
}