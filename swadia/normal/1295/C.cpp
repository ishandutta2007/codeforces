#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

set<int> st[30];
bool visit[30];
string s,t;

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int ans=1;
		for (int i=0;i<30;i++)
		{
			st[i].clear();
			visit[i]=0;
		}
		cin>>s>>t;
		for (int i=0;i<s.size();i++)
		{
			st[s[i]-'a'].insert(i);
			visit[s[i]-'a']=1;
		}
		int cur=-1;
		for (auto p:t)
		{
			if (!visit[p-'a'])
			{
				ans=-1;
				break;
			}
			auto s=st[p-'a'].lower_bound(cur+1);
			if (s==st[p-'a'].end())
			{
				ans++;
				s=st[p-'a'].upper_bound(-1);
			}
			cur=*s;
			//WRT(cur);
			//WRT(ans);
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}