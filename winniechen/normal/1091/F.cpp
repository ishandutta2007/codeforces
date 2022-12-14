#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100005
#define ll long long
int n,flg;ll a[N],now,ans,res,tmp;
char s[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);scanf("%s",s+1);
	flg=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='W'&&s[flg]=='G')flg=i;
		if(s[i]=='L')now-=a[i];
		else now+=a[i];
		if(now<=0)a[flg]-=now,now=0;
	}
	now=0;
	for(int i=1;i<=n;i++)
	{
		ll tmp=a[i];
		if(s[i]=='W')now+=tmp,ans+=2*tmp;
		if(s[i]=='G')
		{
			ll tnp=min(tmp,now);
			now-=tnp,ans+=2*tnp;
			ans+=3*(tmp-tnp);
		}
		if(s[i]=='L')
		{
			ll tnp=min(tmp,now);
			now-=tnp,tmp-=tnp,ans+=2*tnp;
			ans+=3*tmp;
		}
	}
	printf("%lld\n",ans);
}
//sdasdasdas