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
	int n,k;
	cin>>n>>k;
	int a[n],b[k],s=0;
	bool chk[8000009]={0};
	rep(i,n){
		cin>>a[i];
		s+=a[i];
		a[i]=s;
		chk[s+4000000]=true;
	}

	rep(i,k){
		cin>>b[i];
	}
	sort(a,a+n);sort(b,b+k);
	int ans=0;
	rep(i,n){
		int d=a[i]-b[0]+4000000;
		bool flag=false;
		if (i>0&&a[i]==a[i-1])
		{
			continue;
		}
		if (k>n-i)
		{
			break;
		}
		repA(i,1,k-1){
			ll x=b[i];
			x+=d;
			if (x<8000009&&x>0&&chk[x])
			{
				continue;
			}
			else{
				flag=true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}