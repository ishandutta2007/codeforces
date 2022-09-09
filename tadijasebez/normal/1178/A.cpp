#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int &i:a) scanf("%i",&i);
	vector<int> ans;
	ans.pb(1);
	for(int i=1;i<n;i++) if(a[i]*2<=a[0]) ans.pb(i+1);
	int sum=0,my=0;
	for(int i:a) sum+=i;
	for(int i:ans) my+=a[i-1];
	if(my*2>sum)
	{
		printf("%i\n",ans.size());
		for(int i:ans) printf("%i ",i);
	}
	else printf("0\n");
	return 0;
}