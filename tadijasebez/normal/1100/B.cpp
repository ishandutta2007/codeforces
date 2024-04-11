#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
struct SegmentTree
{
	int mn[M];
	void init(){ for(int i=0;i<M;i++) mn[i]=0;}
	SegmentTree(){ init();}
	void Set(int i, int f){ i+=N;mn[i]=f;for(i>>=1;i;i>>=1) mn[i]=min(mn[i<<1],mn[i<<1|1]);}
	int Get(int l, int r)
	{
		int ans=inf;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans=min(ans,mn[l++]);
			if(r%2==0) ans=min(ans,mn[r--]);
		}
		return ans;
	}
} ST;
int cnt[N];
int main()
{
	int n,m,i,x;
	scanf("%i %i",&n,&m);
	ST.init();
	int t=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%i",&x);
		cnt[x]++;
		ST.Set(x,cnt[x]);
		if(ST.Get(1,n)==t) t++,printf("1");
		else printf("0");
	}
	return 0;
}