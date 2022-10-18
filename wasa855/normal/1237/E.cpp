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
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	if(n==1||n==2)
	{
		cout<<"1\n"; return 0;
	}
	int x=4,y=5;
	while(max(x,y)<n)
	{
		int tx=x,ty=y;
		if(tx&1) x=tx+ty+1,y=ty+ty+1;
		else x=tx+ty+1,y=tx+tx+1;
		if(x>y) swap(x,y);
	}
	if(n==x||n==y) cout<<"1\n";
	else cout<<"0\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}