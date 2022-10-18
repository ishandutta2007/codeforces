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
#define int long long
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
int a,b,c,d;
int ck(int F)
{
	int atk=a*F;
	int L=d*(F-1)+1;
	int e=max(0LL,(L-c+d-1)/d);
	int r=(F-e)*L-(e*d-d+F*d+2)*(F-e)/2;
	// printf("-- %d %d %d %d\n",L,F,e,r);
	atk-=(e*c+r)*b;
	return atk;
}
void work()
{
	a=read(),b=read(),c=read(),d=read();
	if(a>c*b) {printf("-1\n"); return ;}
	int l=1,r=1e6+5,ans;
	// for(int i=1;i<=5;i++) printf("%d %d\n",i,ck(i));
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ck(mid)>=ck(mid+1)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ck(ans));
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}