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

#define MAXN 1010000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int v[MAXN];
int len[MAXN];
LL diff[MAXN];
int a[MAXN];

int main()
{
	int n,w,x;
	cin>>n>>w;
	RPT(i,1,n+1)
	{
		scanf("%d",&len[i]);
		RPT(j,1,len[i]+1)
			scanf("%d",&v[j]);
		int mx=-INF;
		for (int j=1;j<=min(len[i],w-len[i]);j++)
		{
			mx=max(mx,v[j]);
			if (j!=w-len[i]+1)
				a[j]=0;
			else
				a[j]=-INF;
			a[j]=max(a[j],mx);
			diff[j]+=a[j]-a[j-1];
			//cout<<'+'<<' '<<j<<endl;
		}
		mx=-INF;
		int l=1,r=min(len[i],w-len[i]);
		//WRT(l);
		//WRT(r);
		if (len[i]*2>w)
		{
			multiset<int,greater<int> > st;
			RPT(j,1,r+1)
				st.insert(v[j]);
			while (1)
			{
				if (r==len[i])
					break;
				r++;
				st.insert(v[r]);
				a[r]=*(st.begin());
				diff[r]+=a[r]-a[r-1];
				st.erase(v[l]);
				l++;
			}
		}
		for (int j=w;j>=max(len[i],w-len[i])+1;j--)
		{
			mx=max(mx,v[j-w+len[i]]);
			if (j!=len[i])
				a[j]=0;
			else
				a[j]=-INF;
			a[j]=max(a[j],mx);
		}
		for (int j=w;j>=max(len[i]+1,w-len[i]+1)+1;j--)
			diff[j]+=a[j]-a[j-1];
		diff[max(len[i]+1,w-len[i]+1)]+=a[max(len[i]+1,w-len[i]+1)]-a[r];
	}
	LL ans=0;
	RPT(i,1,w+1)
	{
		ans+=diff[i];
		//printf("%d ",ans);
		cout<<ans<<' ';
	}
	return ~~(0^_^0);
}