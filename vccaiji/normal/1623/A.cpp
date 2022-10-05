#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int jj=1;jj<=t;jj++)
	{
		int n,m,rb,rd,cb,cd;
		scanf("%d%d%d%d%d%d",&n,&m,&rb,&cb,&rd,&cd);
		int ans1,ans2;
		if(rb<=rd) ans1=rd-rb;
		else ans1=n-rb+n-rd;
		if(cb<=cd) ans2=cd-cb;
		else ans2=m-cb+m-cd;
		printf("%d",min(ans1,ans2));
		if(jj<t) printf("\n");
	}
	return 0;
}