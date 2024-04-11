#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
int a[max_n];
const int max_x=5e5+20;
int cnt[max_x];
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		++cnt[a[i]];
	}
	for(int i=1;i<=x+10;++i)
	{
		cnt[i+1]+=cnt[i]/(i+1);
		cnt[i]%=i+1;
	}
	bool ok=true;
	for(int i=1;i<=x-1;++i)
	{
		if(cnt[i]>0)
		{
			ok=false;
			break;
		}
	}
	puts(ok?"Yes":"No");
	return 0;
}