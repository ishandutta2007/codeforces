#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN],p[MAXN],t[MAXN];
int st[MAXN],pt[MAXN],tt[MAXN];
int sl,pl,tl;
int q; 
int main()
{
	cin>>q;
	while (q--)
	{
		RPT(i,'a','z'+1)
			st[i]=pt[i]=tt[i]=0;
		bool f=true;
		cin>>s>>t>>p;
		sl=strlen(s);
		tl=strlen(t);
		pl=strlen(p);
		RPT(i,0,sl)
			st[s[i]]++;
		RPT(i,0,tl)
			tt[t[i]]++;
		RPT(i,0,pl)
			pt[p[i]]++;
		RPT(i,'a','z'+1)
			if (st[i]+pt[i]<tt[i] || st[i]>tt[i])
			{
				f=false;
				break;
			}
		if (!f)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int cnt=0;
		RPT(i,0,tl)
		{
			if (t[i]==s[cnt])
				cnt++;
		}
		if (cnt!=sl)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return ~~(0^_^0);
}