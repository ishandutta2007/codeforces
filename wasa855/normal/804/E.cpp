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
int n;
void d(int x,int y,int tag)
{
	if(tag&&(n%4==1))
	{
		printf("%d %d\n",x,n);
		printf("%d %d\n",x,y);
		printf("%d %d\n",y,n);
	}
	else printf("%d %d\n",x,y);
}
void solve1(int x)
{
	d(x+0,x+1,1),d(x+2,x+3,1);
	d(x+1,x+2,0),d(x+0,x+3,0);
	d(x+0,x+2,0),d(x+1,x+3,0);
}
void solve2(int x,int y)
{
	d(x+0,y+0,0);d(x+1,y+1,0);d(x+2,y+2,0);d(x+3,y+3,0);
	d(x+0,y+1,0);d(x+1,y+2,0);d(x+2,y+3,0);d(x+3,y+0,0);
	d(x+0,y+3,0);d(x+1,y+0,0);d(x+2,y+1,0);d(x+3,y+2,0);
	d(x+0,y+2,0);d(x+1,y+3,0);d(x+2,y+0,0);d(x+3,y+1,0);
}
signed main()
{
	cin>>n;
	if(n==1){cout<<"YES\n"; return 0;}
	if(n%4==2||n%4==3) {cout<<"NO\n"; return 0;}
	cout<<"YES\n";
	for(int i=0;i<n/4;i++) solve1(i*4+1);
	for(int i=0;i<n/4;i++)
	{
		for(int j=i+1;j<n/4;j++) solve2(i*4+1,j*4+1);
	}
	return 0;
}