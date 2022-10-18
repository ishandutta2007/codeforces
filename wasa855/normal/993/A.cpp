#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
struct Node
{
	int x,y;
};
Node a[5],b[5];
bool cmp(Node x,Node y)
{
	if(x.y!=y.y) return x.y<y.y;
	return x.x<y.x;
}
bool ok(int x,int y)
{
	if(x>=a[1].x&&x<=a[2].x&&y>=a[1].y&&y<=a[3].y) return 1;
	return 0;
}
signed main()
{
	for(int i=1;i<=4;i++) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=4;i++) b[i].x=read(),b[i].y=read();
	sort(a+1,a+4+1,cmp),sort(b+1,b+4+1,cmp);
	for(int i=b[1].y;i<=b[2].y;i++)
	{
		for(int j=b[1].x-(i-b[1].y);j<=b[1].x+(i-b[1].y);j++)
		{
			// printf("%d %d\n",j,i);
			if(ok(j,i)) {cout<<"YES\n"; return 0;}
		}
	}
	for(int i=b[4].y;i>=b[2].y;i--)
	{
		for(int j=b[1].x-(b[4].y-i);j<=b[1].x+(b[4].y-i);j++)
		{
			if(ok(j,i)) {cout<<"YES\n"; return 0;}
		}
	}
	cout<<"NO\n";
	return 0;
}