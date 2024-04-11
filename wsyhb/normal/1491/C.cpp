#include<bits/stdc++.h>
using namespace std;
const int max_n=5e3+5;
int S[max_n],f[max_n];
int get_fa(int x)
{
	return f[x]!=x?f[x]=get_fa(f[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		if(x>y)
			swap(x,y);
		f[x]=y;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",S+i);
			f[i]=i;
		}
		f[n+1]=n+1;
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
//			printf("i=%d\n",i); 
			if(S[i]>max(n-i,1))
			{
//				printf("ans=%lld\n",ans);
				ans+=S[i]-max(n-i,1);
//				printf("ans=%lld\n",ans);
				S[i]=max(n-i,1);
			}
			while(S[i]>1)
			{
				++ans;
				int j=i;
				while(j<=n)
				{
//					printf("%d ",j);
					int Next=j+S[j];
					S[j]=max(S[j]-1,1);
					if(S[j]==1)
						merge(j,j+1);
					j=Next<=n+1?get_fa(Next):Next;
				}
//				printf("%d------\n",j);
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}