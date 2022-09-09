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
	int n,k,m,i;
	scanf("%i %i %i",&n,&m,&k);
	vector<int> b(n),dif;
	int sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%i",&b[i]);
		if(i) dif.pb(b[i]-b[i-1]-1);
	}
	sum=b[n-1]-b[0]+1;
	sort(dif.begin(),dif.end());
	while(--k && dif.size()) sum-=dif.back(),dif.pop_back();
	printf("%i\n",sum);
	return 0;
}