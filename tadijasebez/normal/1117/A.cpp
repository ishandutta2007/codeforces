#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	int mx=0;
	for(int &i:a) scanf("%i",&i),mx=max(mx,i);
	int ans=1,cnt=0;
	for(int i:a)
	{
		if(i==mx) cnt++;
		else cnt=0;
		ans=max(ans,cnt);
	}
	printf("%i\n",ans);
	return 0;
}