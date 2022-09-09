#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=300050;
struct BIT
{
	ull sum[N];
	void init(){ for(int i=0;i<N;i++) sum[i]=0;}
	BIT(){ init();}
	void Set(int i, ull f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	ull Get(int i){ ull ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	ull Get(int l, int r){ return Get(r)-Get(l-1);}
} ST[2];
int a[N];
ull po[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	vector<int> base={33,71,97,45,37};
	for(int b:base)
	{
		ST[0].init();ST[1].init();
		po[0]=1;for(i=1;i<N;i++) po[i]=po[i-1]*b;
		for(i=1;i<=n;i++)
		{
			int can=min(a[i]-1,n-a[i]);
			if(ST[0].Get(a[i],a[i]+can)*po[n-a[i]-can]!=ST[1].Get(n-a[i]+1,n-a[i]+1+can)*po[a[i]-1-can])
			{
				printf("YES\n");
				return 0;
			}
			ST[0].Set(a[i],po[a[i]]);
			ST[1].Set(n-a[i]+1,po[n-a[i]+1]);
		}
	}
	printf("NO\n");
	return 0;
}