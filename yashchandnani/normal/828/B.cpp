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
	int n,m,count=0;
	cin>>n>>m;
	int a[2][2];
	a[0][0]=101;
	a[1][0]=101;
	a[1][1]=-101;
	a[0][1]=-101;
	char c;
	for (int i = 0; i <n ; ++i)
	{
		rep(j,m){
			cin>>c;
			if (c=='B')
			{
				count++;
				if (i<a[0][0])
				{
					a[0][0]=i;
				}
				if (i>a[0][1])
				{
					a[0][1]=i;
				}
				if (j<a[1][0])
				{
					a[1][0]=j;
				}
				if (j>a[1][1])
				{
					a[1][1]=j;
				}
			}
		}
	}
	
	if (count==0)
	{
		cout<<1<<endl;
	}
	else if (a[0][1]-a[0][0]>a[1][1]-a[1][0])
	{
		if (a[0][1]-a[0][0]<m)
		{
			cout<<(a[0][1]-a[0][0]+1)*(a[0][1]-a[0][0]+1)-count<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	else{
		if (a[1][1]-a[1][0]<n)
		{
			cout<<(a[1][1]-a[1][0]+1)*(a[1][1]-a[1][0]+1)-count<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}

	
	return 0;
}