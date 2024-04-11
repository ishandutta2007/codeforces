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
bool chk[600009];
bool v[1200009];
bool a[20];
int p[22];
void build(int vt,int l ,int r){
	
	if (l==r)
	{
		v[vt]=chk[l];
	}
	else{
		int m=(l+r)/2;
		build(2*vt,l,m);
		build(2*vt+1,m+1,r);
		v[vt]=(v[2*vt]&&v[2*vt+1]);
	}
	return;

}
int find(){
	int vt =1,ans=0;
	repD(i,18,0){
		if (a[i]==true)
		{
			if (v[2*vt+1]==false)
			{
				
				vt*=2;
				vt++;
			}
			else{
				ans+=p[i];
				vt*=2;
			}
		}
		else{
			if (v[2*vt]==false)
			{
				
				vt*=2;
				
			}
			else{
				ans+=p[i];
				vt*=2;
				vt++;
				
			}

		}
		
	}
	return ans;
}
int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pp=1;
    rep(i,22){
    	p[i]=pp;
    	pp*=2;
    }
	int n,m;cin>>n>>m;
	rep(i,n){
		int x;cin>>x;
		chk[x]=true;
	}
	int z = p[19];
	z--;
	
	build(1,0,z);
	int y =0;
	rep(i,m){
		int x;cin>>x;
		y^=x;
		rep(i,19){
			a[i]=y&(1<<i);
		}
		int ans=find();
		cout<<ans<<"\n";

	}
	
	return 0;
}