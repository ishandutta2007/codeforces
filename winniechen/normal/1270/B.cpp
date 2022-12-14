#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int a[N],n;
void solve()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)if(abs(a[i+1]-a[i])>1)return printf("YES\n%d %d\n",i,i+1),void();
	puts("NO");
}
int main(){int T;scanf("%d",&T);while(T--)solve();}