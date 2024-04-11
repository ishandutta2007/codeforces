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
int a[N],b[N];
vector<pair<pair<int,int>,int>> lo,hi;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&a[i],&b[i]);
		if(a[i]<b[i])
		{
			lo.pb({{b[i],a[i]},i});
		}
		else
		{
			hi.pb({{a[i],b[i]},i});
		}
	}
	vector<pair<pair<int,int>,int>> ans;
	if(hi.size()>lo.size()) ans=hi;
	else ans=lo;
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	if(hi.size()>lo.size()) reverse(ans.begin(),ans.end());
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i ",p.second);
	return 0;
}