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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;cin>>n;
	std::vector<ii> a;
	rep(i,n){
		int x;cin>>x;
		a.pb(mp(x,i));
	}
	sortA(a);
	std::vector<int> v[n+1];
	int ans=0;
	bool chk[n]={false};
	rep(i,n){
		if (chk[i]==true)
		{
			continue;
		}
		ans++;
		v[ans].pb(i+1);
		int st = i;
		int end = a[i].se;
		int count = 1;
		while(st!=end){
			v[ans].pb(end+1);
			chk[end]=true;
			end = a[end].se;
			count++;
		}

	}
	cout<<ans<<endl;
	rep(i,ans){
		cout<<v[i+1].size()<<" ";
		rep(j,v[i+1].size()){
			cout<<v[i+1][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}