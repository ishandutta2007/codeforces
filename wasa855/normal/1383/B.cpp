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
int a[35];
void work()
{
	memset(a,0,sizeof(a));
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int j=0;j<=30;j++)
		{
			if(x&(1<<j)) a[j]++;
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(!(a[i]&1)) continue;
		if(a[i]%4==1) {cout<<"WIN\n"; return ;}
		else if(n%2==0) {cout<<"WIN\n"; return ;}
		else {cout<<"LOSE\n"; return ;}
	}
	cout<<"DRAW\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}