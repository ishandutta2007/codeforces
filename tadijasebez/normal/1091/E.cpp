#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=500050;
int a[N];
ll sum[N];
const int inf=1e9+7;
int main()
{
	int n,i;
	scanf("%i",&n);
	int odd=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]&1) odd^=1;
	}
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll L=0,R;
    ll sl=0,sr=n;
    for(i=1;i<=n;i++)
	{
		L+=a[i];
		int top=n,bot=i+1,mid,taj=n+1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(a[mid]<=i) taj=mid,top=mid-1;
			else bot=mid+1;
		}
		int sz=taj-i-1;
		R=sum[n]-sum[taj-1]+(ll)sz*i+(ll)i*(i-1);
        ll dif=R-L;
        //printf("R:%lld L:%lld taj:%i\n",R,L,taj);
        ll l=0,r=-1;
        r=dif+a[i]+min(i,a[i]);
        r=max(r,(ll)a[i]-1);
        /*top=n,bot=a[i];
        while(top>=bot)
		{
			mid=top+bot>>1;
			ll AL=L+mid-a[i];
			ll AR=R+min(i,a[i]);
			if(AR-AL<=0) r=mid,bot=mid+1;
			else top=mid-1;
		}*/
		if(i>=-dif)
		{
			l=-dif;
		}
		else l=a[i];
		/*top=a[i],bot=0;
		while(top>=bot)
		{
			mid=top+bot>>1;
			ll AL=L;
			ll AR=R+min(i,mid);
			if(AR-AL<=0)
		}*/
		//printf("%i %i\n",l,r);
		ckmx(sl,l);
		ckmn(sr,r);
	}
	if(sl>sr) printf("-1\n");
	else
	{
		int cnt=0;
		for(int i=sl;i<=sr;i++)
		{
			if(odd && i%2==1) printf("%i ",i),cnt++;
			else if(!odd && i%2==0) printf("%i ",i),cnt++;
		}
		if(!cnt) printf("-1\n");
	}
	return 0;
}