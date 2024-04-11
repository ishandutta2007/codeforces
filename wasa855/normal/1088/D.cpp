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
int query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int f=query(0,0);
	int a=0,b=0;
	for(int i=29;i>=0;i--)
	{
		int x=query(1<<i|a,1<<i|b);
		if(x==f)
		{
			int y=query(1<<i|a,b);
			if(y==-1) a|=1<<i,b|=1<<i;
		}
		else
		{
			if(f==1) a|=1<<i;
			else b|=1<<i;
			f=query(a,b);
		}
	}
	printf("! %d %d\n",a,b);
	fflush(stdout);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}