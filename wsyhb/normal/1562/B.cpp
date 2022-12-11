#include<bits/stdc++.h>
using namespace std;
const int max_k=50+5;
char n[max_k];
int cnt[10];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d%s",&k,n);
		int pos=-1;
		for(int i=0;i<=k-1;++i)
		{
			if(n[i]=='1'||n[i]=='4'||n[i]=='6'||n[i]=='8'||n[i]=='9')
			{
				pos=i;
				break;
			}
		}
		if(pos!=-1)
		{
			puts("1");
			printf("%c\n",n[pos]);
			continue;
		}
		for(int i=1;i<=9;++i)
			cnt[i]=0;
		for(int i=0;i<=k-1;++i)
			++cnt[n[i]-'0'];
		int val=-1;
		for(int i=1;i<=9;++i)
		{
			if(cnt[i]>=2)
			{
				val=i;
				break;
			}
		}
		if(val!=-1)
		{
			puts("2");
			printf("%d%d\n",val,val);
			continue;
		}
		assert(k<=4);
		int ans_cnt=5,ans_val=-1;
		for(int s=1;s<(1<<k);++s)
		{
			int cnt=0,val=0;
			for(int i=0;i<k;++i)
			{
				if(s>>i&1)
					++cnt,val=val*10+(n[i]-'0');
			}
			bool flag=false;
			for(int i=2;i<=val-1;++i)
			{
				if(val%i==0)
				{
					flag=true;
					break;
				}
			}
			if(flag&&cnt<ans_cnt)
				ans_cnt=cnt,ans_val=val;
		}
		assert(ans_val!=-1);
		printf("%d\n%d\n",ans_cnt,ans_val);
	}
    return 0;
}