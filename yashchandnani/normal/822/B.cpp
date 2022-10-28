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
	int a,b;
	cin>>a>>b;
	string s,t;
	cin>>s;
	cin>>t;
	int ans[t.size()-s.size()+1]={0};
	rep(i,s.size()){
		rep(j,t.size()-s.size()+1){
			if (s[i]==t[i+j])
			{
				ans[j]++;
			}

		}
	}
	int max=ans[0],id=0;
	repA(i,1,t.size()-s.size()){
		if (max<ans[i])
		{
			max=ans[i];
			id=i;
		}
	}
	cout<<s.size()-max<<endl;
	rep(i,s.size()){
		if (s[i]!=t[i+id])
		{
			cout<<i+1<<" ";
		}
	}


	
	return 0;
}