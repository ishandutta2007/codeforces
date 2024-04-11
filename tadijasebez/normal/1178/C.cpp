#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int ans=1;
	n+=m;
	while(n--) ans=add(ans,ans);
	printf("%i\n",ans);
	return 0;
}