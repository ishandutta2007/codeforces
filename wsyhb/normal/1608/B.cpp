#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char str[max_n];
int ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		str[1]=a>b?'<':'>';
		for(int i=2;i<=n-1;++i)
		{
			if(str[i-1]=='<')
			{
				if(a>0)
				{
					str[i]='>';
					--a;
				} 
				else
					str[i]='<';
			}
			else
			{
				if(b>0)
				{
					str[i]='<';
					--b;
				}
				else
					str[i]='>';
			}
		}
		if(a||b)
			puts("-1");
		else
		{
			for(int i=1;i<=n;++i)
				ans[i]=0;
			int L=1,R=n;
			for(int i=2;i<=n-1;++i)
			{
				if(str[i-1]!=str[i])
				{
					if(str[i-1]=='<')
						ans[i]=R--;
					else
						ans[i]=L++;
				}
			}
			for(int i=1;i<=n;++i)
			{
				if(ans[i])
					continue;
				int j=i;
				while(j+1<=n&&!ans[j+1])
					++j;
				if(j==i||str[i]=='<')
				{
					for(int k=i;k<=j;++k)
						ans[k]=L++;
				}
				else
				{
					for(int k=i;k<=j;++k)
						ans[k]=R--;
				}
				i=j;
			}
//			fprintf(stderr,"L=%d R=%d\n",L,R);
			assert(L==R+1);
			for(int i=1;i<=n;++i)
				printf("%d%c",ans[i],i<n?' ':'\n');
		}
	}
	return 0;
}