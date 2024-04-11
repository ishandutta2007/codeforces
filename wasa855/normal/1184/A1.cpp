#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i*i<=n;i++)
	{
		int sum=i*i+i+1;
		int x=n-sum;
		if(x<=0) break;
		if(x%(2*i)==0)
		{
			printf("%I64d %I64d\n",i,x/2/i);
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
 //csefe