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
	int n,x;
	std::vector<int> v[100007];
	cin>>n;
	rep(i,n){
		cin>>x;
		v[x].pb(i);
	}
	ll ans=0,c=0,max=-1;
	rep(i,100002){
		
		if (v[i].size()==0)
		{
			continue;
		}
		else if(v[i][0]>max){
			c+=v[i].size();
			max=v[i].back();
			continue;
		}
		else{
			int idx=lower_bound(v[i].begin(),v[i].end(),max)-v[i].begin();
			
			c+=v[i].size()-idx;

			ans+=n;
			n-=c;
			c=0;
			max=v[i][idx-1];
			c+=idx;
		}

		
	}
	cout<<ans+n<<endl;
	return 0;
}