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
	char c;
	int a[26];
	char b[26],d[26];
	rep(i,26){
		cin>>d[i];
		a[d[i]-'a']=i;
	}
	rep(i,26){
		cin>>b[i];

	}
	string s;
	cin>>s;
	rep(i,s.size()){
		if (s[i]>=97)
		{
			cout<<b[a[s[i]-'a']];
		}
		else if (s[i]<=60)
		{
			cout<<s[i];
		}
		else{
			cout<<(char)(b[a[s[i]-'A']]-32);
		}
	}

	
	return 0;
}