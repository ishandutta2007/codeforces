#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=300050;
char s[N];
int nxt[N];
map<char,int> last;
int main()
{
	int n;
	scanf("%i",&n);
	scanf("%s",s+1);
	int cnt=1;
	for(int i=1;i<n;i++) if(s[i]!=s[i+1]) cnt++;
	last['A']=last['B']=n+1;
	for(int i=n;i>=1;i--) nxt[i]=last[s[i]],last[s[i]]=i;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			int z=n-i+1-min(cnt,2);
			//printf("%i ",z);
			ans+=z;
		}
		else
		{
			int z=n-nxt[i]+1;
			//printf("%i ",z);
			ans+=z;
			cnt--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}