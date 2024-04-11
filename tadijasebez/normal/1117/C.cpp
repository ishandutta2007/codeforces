#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
char s[N];
int main()
{
	int x1,y1,x2,y2;
	scanf("%i %i",&x1,&y1);
	scanf("%i %i",&x2,&y2);
	int n;
	scanf("%i",&n);
	scanf("%s",s+1);
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(s[i]=='U') a[i]++;
		if(s[i]=='D') a[i]--;
		if(s[i]=='L') b[i]--;
		if(s[i]=='R') b[i]++;
	}
	ll top=1e18,bot=1,mid,ans=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		ll ny=y1+a[mid%n]+mid/n*a[n];
		ll nx=x1+b[mid%n]+mid/n*b[n];
		//printf("mid:%lld x:%lld y:%lld %lld\n",mid,nx,ny,abs(nx-x2)+abs(ny-y2));
		if(abs(nx-x2)+abs(ny-y2)<=mid) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}