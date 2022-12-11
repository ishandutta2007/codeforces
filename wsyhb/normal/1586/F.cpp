// idea by mango_lassi
#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
const int max_c=10+5;
int Len[max_n][max_c];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int t=1,c=0;
	while(t<n)
		t*=k,++c;
	for(int i=1;i<=n;++i)
	{
		int t=i-1;
		for(int j=1;j<=c&&t;++j)
		{
			Len[i][j]=t%k;
			t/=k;
		}
	}
	printf("%d\n",c);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			int col=-1;
			for(int k=1;k<=c;++k)
			{
				if(Len[j][k]>Len[i][k])
				{
					col=k;
					break;
				}
			}
			assert(col!=-1);
			printf("%d%c",col,i==n-1&&j==n?'\n':' ');
		}
	return 0;
}