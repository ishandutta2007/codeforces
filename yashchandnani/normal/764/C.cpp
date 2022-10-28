#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
#define _  %  MODULUS
#define __ %= MODULUS


#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key


int main(){

	int n;
	cin>>n;
	
	int a[n+1],u,v;
	
	
	vii g;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>u>>v;
		g.pb(mp(u,v));

	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i+1];
	}
	int flag=0;
	for (int i = 0; i < n-1; ++i)
	{
		if (a[g[i].fi]!=a[g[i].se])
		{
			if (flag==0)
			{
				u=g[i].fi;
				v=g[i].se;
				flag++;
			}
			else if (flag==1)
			{
				if (u!=g[i].fi&&u!=g[i].se)
				{
					if (v==g[i].fi||v==g[i].se)
					{
						swap(u,v);
					}
					else{
						u=-1;
					}
				}
				flag++;
			}
			else{
				if (u!=g[i].fi&&g[i].se!=u)
				{
					u=-1;
				}

			}
		}
		if (u==-1)
		{
			break;
		}
	}
	if (u==-1)
	{
		cout<<"NO";

	}
	else{
		cout<<"YES\n"<<u;
	}
	
	return 0;
}