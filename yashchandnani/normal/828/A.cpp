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


int main()
{
	int n,a,b,c=0,x,ans=0;
	cin>>n>>a>>b;
	rep(i,n){
		cin>>x;
		if (x==1)
		{
			if (a!=0)
			{
				a--;
				continue;
			}
			else if (b!=0)
			{
				b--;
				c++;
				continue;
			}
			else if (c!=0)
			{
				c--;
				continue;
			}
			else {
				ans++;
			}
		}
		else{
			if (b!=0)
			{
				b--;
				continue;
			}
			else{
				ans+=2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}