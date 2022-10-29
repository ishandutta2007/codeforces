#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int a[500005];
struct node
{
	int x,y;
}b[500005];
map <int,int> mp;
int cnt=0;
inline bool cmp(node x,node y)
{
	return x.y>y.y;
}
int c[500005],ans1[11][500005],ans2[101][50005],ans3[5005][5005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
			continue;
		b[++cnt].x=a[i];
		b[cnt].y=mp[a[i]];
	}
	for(int i=1;i<=cnt;i++)
		--c[b[i].y+1];
	c[1]=cnt;
	for(int i=2;i<=n;i++)
		c[i]+=c[i-1];
	for(int i=2;i<=n;i++)
		c[i]+=c[i-1];
	int mx=0,x,y;
	for(int i=1;i<=n;i++)
	{
		int t=n/i;
		if(t<i) break;
		int now=min(c[i],i*t);
		t=now/i,now=t*i;
		if(t<i) continue;
		if(now>mx)
			mx=now,x=i,y=t;
	}
	cout << mx << endl << x << " " << y << endl;
	sort(b+1,b+cnt+1,cmp);
	int nowx=0,nowy=0;
	if(x<=10)
	{
		for(int i=1;i<=cnt;i++)
		{
			b[i].y=min(b[i].y,x);
			for(int j=1;j<=b[i].y;j++)
			{
				++nowx,++nowy;
				if(nowx==x+1) nowx-=x;
				if(nowy==y+1) nowy-=y;
				if(ans1[nowx][nowy])
				{
					for(int k=1;k<=y;k++)
					{
						if(!ans1[1][k])
						{
							nowx=1,nowy=k;
							break;
						}
					}
				}
				ans1[nowx][nowy]=b[i].x;
			}
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
				cout << ans1[i][j] << " ";
			cout << endl;
		}
	}
	else 
	if(x<=100)
	{
		for(int i=1;i<=cnt;i++)
		{
			b[i].y=min(b[i].y,x);
			for(int j=1;j<=b[i].y;j++)
			{
				++nowx,++nowy;
				if(nowx==x+1) nowx-=x;
				if(nowy==y+1) nowy-=y;
				if(ans2[nowx][nowy])
				{
					for(int k=1;k<=y;k++)
					{
						if(!ans2[1][k])
						{
							nowx=1,nowy=k;
							break;
						}
					}
				}
				ans2[nowx][nowy]=b[i].x;
			}
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
				cout << ans2[i][j] << " ";
			cout << endl;
		}
	}
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			b[i].y=min(b[i].y,x);
			for(int j=1;j<=b[i].y;j++)
			{
				++nowx,++nowy;
				if(nowx==x+1) nowx-=x;
				if(nowy==y+1) nowy-=y;
				if(ans3[nowx][nowy])
				{
					for(int k=1;k<=y;k++)
					{
						if(!ans3[1][k])
						{
							nowx=1,nowy=k;
							break;
						}
					}
				}
				ans3[nowx][nowy]=b[i].x;
			}
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
				cout << ans3[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}