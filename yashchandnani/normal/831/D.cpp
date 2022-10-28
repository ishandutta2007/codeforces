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

ll mod(int x){
	if (x<0)
	{
		return -x;
	}
	return x;
}


int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	int a[n],b[k];
	rep(i,n){
		cin>>a[i];
	}
	rep(i,k){
		cin>>b[i];
	}
	sort(a,a+n);sort(b,b+k);
	ll ans[n][k]={0};
	rep(i,n){
		repA(j,i,k-1){
			ll x=mod(a[i]-b[j])+mod(b[j]-p);
			if (i==0)
			{
				if (j==0)
				{
					ans[i][j]=x;
				}
				else{
					ans[i][j]=min(x,ans[i][j-1]);
				}
				continue;
			}
			x=max(x,ans[i-1][j-1]);

			if (x<ans[i][j-1]||j==i)
			{
				ans[i][j]=x;
			}
			else{
				ans[i][j]=ans[i][j-1];
			}
		}
	}
	cout<<ans[n-1][k-1]<<endl;
	return 0;
}