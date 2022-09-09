#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],b[N];
int main()
{
    int n,i;
    scanf("%i",&n);
    int ans=1;
    for(i=1;i<=n;i++)
	{
		scanf("%i %i",&a[i],&b[i]);
		ans+=max(min(a[i],b[i])-max(a[i-1],b[i-1])+1,0);
		if(a[i-1]==b[i-1]) ans--;
	}
	printf("%i\n",ans);
	return 0;
}