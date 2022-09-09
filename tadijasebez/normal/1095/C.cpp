#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	multiset<int> ans;
	int n,k,i;
	scanf("%i %i",&n,&k);
	while(n) ans.insert(n&-n),n-=n&-n;
	if(ans.size()>k) return 0*printf("NO\n");
	else
	{
		while(ans.size()<k)
		{
			auto it=ans.find(*ans.rbegin());
			if(*it==1) return 0*printf("NO\n");
			int f=*it;
			ans.erase(it);
			ans.insert(f/2);
			ans.insert(f/2);
		}
		printf("YES\n");
		for(int f:ans) printf("%i ",f);
	}
	return 0;
}