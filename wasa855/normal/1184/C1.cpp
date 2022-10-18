#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 15
struct Node
{
	int x,y;
};
Node a[N*4];
int sa[55],sb[55];
bool mapp[55][55];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n*4+1;i++) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n*4+1;i++)
	{
		sa[a[i].x]++,sb[a[i].y]++;
	}
	int co=n;
	int la=0,lb=0,ra=0,rb=0;
	for(int i=0;i<=50;i++)
	{
		if(sa[i]>=co)
		{
			la=i;
			break;
		}
	}
	for(int i=50;i>=0;i--)
	{
		if(sa[i]>=co)
		{
			lb=i;
			break;
		}
	}
	for(int i=0;i<=50;i++)
	{
		if(sb[i]>=co)
		{
			ra=i;
			break;
		}
	}
	for(int i=50;i>=0;i--)
	{
		if(sb[i]>=co)
		{
			rb=i;
			break;
		}
	}
	for(int i=la;i<=lb;i++)
	{
		mapp[i][ra]=true;
		mapp[i][rb]=true;
	}
	for(int i=ra;i<=rb;i++)
	{
		mapp[la][i]=true;
		mapp[lb][i]=true;
	}
	for(int i=1;i<=n*4+1;i++)
	{
		if(mapp[a[i].x][a[i].y]==false)
		{
			printf("%d %d\n",a[i].x,a[i].y);
		}
	}
	return 0;
}
//waewdwf