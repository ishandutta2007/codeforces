#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	string x,y;
	while(T--)
	{
		cin>>x>>y;
		int n=x.length(),m=y.length();
		int a=m-1;
		while(y[a]=='0') a--;
		a+=n-m;
		int b=a;
		while(x[b]=='0') b--;
		printf("%d\n",a-b);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}