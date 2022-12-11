#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(l==r)
			puts(l!=1?"YES":"NO");
		else
		{
			int L=l+(l&1);
			int R=r-(r&1);
			int cnt_even=(R-L)/2+1;
			int cnt_odd=(r-l+1)-cnt_even;
			puts(k>=cnt_odd?"YES":"NO");
		}
	}
	return 0;
}