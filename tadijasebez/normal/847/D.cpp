#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
const int N=200050;
const int M=2*N;
int t[N],cnt[N];
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
struct BIT
{
	int sum[M];
	BIT(){ for(int i=0;i<M;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<M;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} Tree;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,T,i;
	scanf("%i %i",&n,&T);T--;
	for(i=1;i<=n;i++) scanf("%i",&t[i]),id.pb(t[i]-i),id.pb(T-i);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	int sz=id.size();
	int sol=0;
	for(i=1;i<=n;i++)
	{
		if(T<i) break;
		Tree.Set(Find(t[i]-i),1);
		int tm=Find(T-i);
		sol=max(sol,Tree.Get(1,tm));
	}
	printf("%i\n",sol);
	return 0;
}