#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

int c[101],d[101];

int main()
{
	int n,a,b;cin>>n>>a>>b;
	if (a>b)
	{
		swap(a,b);
	}
	int ans=0;
	rep(i,n){
		int x,y;cin>>x>>y;
		repD(i,a,1){
			if ((x<=a-i+1)&&y<=b&&c[i]!=0)
			{
				//cout<<i<<x<<y<<endl;
				ans=max(ans,c[i]+x*y);
			}
			if ((y<=a-i+1)&&x<=b&&c[i]!=0)
			{
				//cout<<i<<x<<y<<endl;
				ans=max(ans,c[i]+x*y);
			}
		}
		repD(i,b,1){
			if (x<=a&&(y<=b-i+1)&&d[i]!=0)
			{
				//cout<<i<<x<<y<<endl;
				ans=max(ans,d[i]+x*y);
			}
			if (y<=a&&(x<=b-i+1)&&d[i]!=0)
			{
				//cout<<i<<x<<y<<endl;
				ans=max(ans,d[i]+x*y);
			}
		}
		if (x<=a&&y<=b)
		{
			d[y+1]=max(d[y+1],x*y);
			c[x+1]=max(c[x+1],x*y);
		}
		if (x<=b&&y<=a)
		{
			d[x+1]=max(d[x+1],x*y);
			c[y+1]=max(c[y+1],x*y);
		}
	}
	cout<<ans<<endl;
	return 0;
}