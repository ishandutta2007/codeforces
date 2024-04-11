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
ll f[1000000];

ll pow(int x){
	if (f[x]!=0)
	{
		return f[x];
	}
	else if (x==0)
	{
		return 1;
	}
	else if (x==1)
	{
		return 2;
	}
	else{
		ll ans=pow(x/2);
		ans*=ans;
		ans%=MOD;
		if (x%2)
		{
			ans*=2;
		}
		ans%=MOD;
		return ans;
	}
}
char c[2000009];
int main()
{
	int n,t;
	cin>>n>>t;
	
	int count=n-1,sz=-1;
	rep(i,n){
		cin>>c[i];
		if (c[i]=='.')
		{
			sz=i;
		}
		if (c[i]>='5'&&t>0&&sz!=-1)
		{
			count=i;
			break;
		}
		
	}
	while(c[count]>='5'&&count>sz&&t>0){
		t--;
		c[count]='0';
		count--;
		if (count==sz)
		{
			count--;
		}
		while(c[count]=='9'){
			c[count]='0';
			count--;
			if (count==-1)
			{
				cout<<"1";
				rep(i,sz){
					cout<<"0";
				}
				return 0;
				
			}
			if (count==sz)
			{
				count--;
			}
		}
		c[count]=(char)((int)c[count]+1);
		
	}
	rep(i,max(count+1,sz)){
		cout<<c[i];
	}

	return 0;
}