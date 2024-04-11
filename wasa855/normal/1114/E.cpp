#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int query(char ch,int x)
{
	printf("%c %d\n",ch,x);
	fflush(stdout);
	return read();
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int l=0,r=1e9;
	int cnt=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		int x=query('>',mid);
		if(x) l=mid+1;
		else r=mid;
		cnt++;
	}
	int maxn=r,ans=0;
	mt19937 rng(time(NULL));
	while(cnt<60)
	{
		cnt++;
		int x=query('?',rng()%n+1);
		ans=__gcd(ans,maxn-x);
	}
	printf("! %d %d\n",maxn-(n-1)*ans,ans);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}