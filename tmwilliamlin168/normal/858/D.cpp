#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

map<ll,int> ma;
string a[100001];
map<ll,int> adj[70001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		//string s; s="123456789";
		string s; cin>>s;
		a[i]=s;
		for(int j=0;j<s.length();j++)
		{
			ll tmp = 0;
			for(int k=j;k<s.length();k++)
			{
				tmp*=12;
				tmp+=s[k]-'0'+1;
				ma[tmp]++;
				adj[i][tmp]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		string res="1000000000";
		string s=a[i];
		for(int j=0;j<s.length();j++)
		{
			ll tmp = 0;
			for(int k=j;k<s.length();k++)
			{
				tmp*=12;
				tmp+=s[k]-'0'+1;
				//cerr<<i<<' '<<tmp<<' '<<ma[tmp]<<' '<<adj[i][tmp]<<'\n';
				if(ma[tmp]==adj[i][tmp])
				{
					if(k-j+1<res.length())
					{
						res=s.substr(j,k-j+1);
					}
				}
			}
		}
		cout<<res<<'\n';
	}
}