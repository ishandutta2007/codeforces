#include<bits/stdc++.h>
using namespace std;
const int max_n=5e3+5;
char s[max_n],t[max_n],S[max_n<<1];
int mat[max_n],len,z[max_n<<1];
inline void Z_algorithm() // 0-indexed
{
	z[0]=0;
	int l=0,r=0;
	for(int i=1;i<len;++i)
	{
		z[i]=max(min(z[i-l],r-i+1),0);
		while(i+z[i]<len&&S[z[i]]==S[i+z[i]])
			++z[i];
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d%s%s",&n,&m,s+1,t+1);
		int cur=0;
		for(int i=1;i<=n;++i)
		{
			if(cur<m&&s[i]==t[cur+1])
				++cur;
			mat[i]=cur;
		}
		if(cur<m)
		{
			puts("-1");
			continue;
		}
		int pos=n+1;
		for(int i=1;i<=n;++i)
		{
			if(mat[i]==mat[i-1])
			{
				pos=i;
				break;
			}
		}
		int ans=n-pos+1;
		for(int i=1;i<=n;++i)
		{
			len=0;
			for(int j=i+1;j<=n;++j)
				S[len++]=s[j];
			S[len++]='*';
			for(int j=1;j<=m;++j)
				S[len++]=t[j];
			S[len]='\0',z[len]=0;
			Z_algorithm();
			for(int j=0;j<=mat[i];++j)
				ans=min(ans,n-z[(n-i)+(j+1)]+i-j+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}