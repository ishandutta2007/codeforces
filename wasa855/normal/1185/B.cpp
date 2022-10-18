#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
void work()
{
	string x,y;
	cin>>x>>y;
	int i=0,j=0;
	int n=x.length(),m=y.length();
	while(i<n&&j<m)
	{
		if(i<n-1&&x[i]==x[i+1])
		{
			if(x[i]==y[j]) i++,j++;
			else
			{
				cout<<"NO\n";
				return ;
			}
		}
		else
		{
			if(x[i]!=y[j])
			{
				cout<<"NO\n";
				return ;
			}
			while(x[i]==y[j])
			{
				j++;
			}
			i++;
		}
//		printf("%d %d\n",i,j);
	}
	if(j==m&&i==n) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}