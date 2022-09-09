#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
ll l[N];
char ty[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&l[i]);
	scanf("%s",ty+1);
	bool has_grass=0,has_water=0;
	ll fg2=0,fw2=0,f=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ty[i]=='G')
		{
			ll need=l[i];
			if(fw2)
			{
				ll work=min(need,fw2);
				fg2+=work*2;
				need-=work;
				fw2-=work;
				ans+=work*2;
			}
			ans+=need*3;
			fg2+=need;
			has_grass=1;
		}
		else if(ty[i]=='W')
		{
			ans+=l[i]*2;
			fw2+=l[i];
			has_water=1;
		}
		else
		{
			ll need=l[i];
			ans+=l[i];
            if(fw2)
			{
                ll work=min(need,fw2);
                fw2-=work;
                need-=work;
                ans+=work;
			}
			if(fg2)
			{
				ll work=min(need,fg2);
				fg2-=work;
				need-=work;
				ans+=work*2;
			}
			if(has_water)
			{
				ans+=need*3;
			}
			else
			{
				ans+=need*5;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}