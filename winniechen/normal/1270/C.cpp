#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int a[N],n;
void solve()
{
	scanf("%d",&n);
	ll sum = 0 ; int x = 0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i],x^=a[i];
	sum+=x; printf("2\n%d %lld\n",x,sum);
}
int main(){int T;scanf("%d",&T);while(T--)solve();}