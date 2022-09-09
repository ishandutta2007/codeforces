#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
int cnt[N];
int main()
{
	int n,k,x;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++) scanf("%i",&x),cnt[x]++;
	int ans=n,odd=0;
	for(int i=1;i<=k;i++) if(cnt[i]&1) odd++;
	if(n&1) odd--;
	ans-=odd/2;
	printf("%i\n",ans);
	return 0;
}