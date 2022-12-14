#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int d[N],n;
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),d[x]++,d[y]++;
	for(int i=1;i<=n;i++)if(d[i]==2)return puts("NO"),0;
	puts("YES");
}