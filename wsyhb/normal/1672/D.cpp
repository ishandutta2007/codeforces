#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],b[max_n],c[max_n];
vector<int> A[max_n],B[max_n];
int cnt[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
			scanf("%d",b+i);
		for(int i=1;i<=n;++i)
		{
			A[i].clear(),B[i].clear();
			cnt[i]=0;
		}
		int len=0;
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&b[j+1]==b[i])
				++j;
			c[++len]=b[i];
			for(int k=1;k<=j-i;++k)
				B[len].push_back(b[i]);
			i=j;
		}
		int cur=len,lst=n+1;
		for(int i=n;i>=1&&cur>0;--i)
		{
			if(a[i]==c[cur])
			{
				for(int j=i+1;j<lst;++j)
					A[cur].push_back(a[j]);
				lst=i;
				--cur;
			}
		}
		if(cur>0)
		{
			puts("NO");
			continue;
		}
		bool ok=true;
		for(int i=len;i>=1;--i)
		{
			for(int j=0;j<int(B[i].size());++j)
				++cnt[B[i][j]];
			for(int j=0;j<int(A[i].size());++j)
			{
				if(!cnt[A[i][j]])
				{
					ok=false;
					break;
				}
				--cnt[A[i][j]];
			}
			if(!ok)
				break;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}