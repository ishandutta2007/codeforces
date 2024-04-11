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
int p[N],n;
vector<pair<int,int>> ans;
void Do(int x, int y)
{
	ans.pb({x,y});
	swap(p[x],p[y]);
}
void Swap(int x, int y)
{
	//printf("s:%i %i\n",x,y);
	if(abs(x-y)*2>=n) Do(x,y);
	else
	{
		if(max(x,y)*2<=n)
		{
			Do(x,n);
			Do(y,n);
			Do(x,n);
		}
		else if(min(x,y)*2>n)
		{
			Do(x,1);
			Do(y,1);
			Do(x,1);
		}
		else
		{
			if(x>y) swap(x,y);
			Do(x,n);
			Do(y,1);
			Do(1,n);
			Do(x,n);
			Do(y,1);
		}
	}
}
int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&p[i]);
	for(int i=1;i<=n;i++)
	{
		while(p[i]!=i)
		{
			Swap(i,p[i]);
		}
	}
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}