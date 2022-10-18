#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int x=read(),y=read(),z=read();
		int t=y+z-x;
		if(t<0) t=-1;
		else t/=2;
		if(t>z) t=z;
		cout<<z-t<<endl;
	}
	return 0;
}