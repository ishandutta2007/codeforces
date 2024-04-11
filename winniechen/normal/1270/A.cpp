#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1;
void solve()
{
	int n,a,b , mx = 0 , p = 0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1,x;i<=a;i++)scanf("%d",&x),mx<x?(p=0,mx=x):0;
	for(int i=1,x;i<=b;i++)scanf("%d",&x),mx<x?(p=1,mx=x):0;
	if(p)puts("NO");else puts("YES");
}
int main(){int T;scanf("%d",&T);while(T--)solve();}