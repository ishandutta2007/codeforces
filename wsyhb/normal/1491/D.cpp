#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int cnt_u=0,cnt_v=0;
		bool flag=true;
		for(int i=0;i<30;++i)
		{
			cnt_u+=(u>>i)&1;
			cnt_v+=(v>>i)&1;
			if(cnt_v>cnt_u)
			{
				flag=false;
				break;
			}
		}
		if(u>v)
			flag=false;
		puts(flag?"YES":"NO");
	}
    return 0;
}