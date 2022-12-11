#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt[2]={0,0};
		for(int i=1;i<=2*n;++i)
		{
			int x;
			scanf("%d",&x);
			++cnt[x&1];
		}
		if(cnt[0]==cnt[1])
			puts("Yes");
		else
			puts("No");
	}
    return 0;
}