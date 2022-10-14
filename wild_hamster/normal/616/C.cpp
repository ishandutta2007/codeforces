#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1005][1005], sz[1005005];
char s[1005][1005];
vector <pair<ll,ll> > f;
set <ll> g;
set <ll> ::iterator itr;
void dfs(ll x, ll y)
{
	if (a[x][y] != 0)
		return;
	if ( x < 0 || x >= n || y < 0 || y >= m)
		return;
	a[x][y] = q;
	k++;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
void ad(ll x, ll y)
{
	if ( x < 0 || x >= n || y < 0 || y >= m)
		return;
	g.insert(a[x][y]);
}

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
    	scanf("%s",s[i]);    	
    }
    for (i = 0; i < n; i++)
    	for (j = 0; j < m; j++)
    		if (s[i][j] == '*')
    			a[i][j] = -1;
    q = 1;
    for (i = 0; i < n; i++)
    	for (j = 0; j < m; j++)
    	if (a[i][j] == 0)
    	{
    		f.clear();
    		k = 0;
    		dfs(i,j);    		
    		sz[q++] = k;
    	}
    for (i = 0; i < n; i++)
    	for (j = 0; j < m; j++)
    		if (s[i][j] == '*')
    		{
    			ll ans = 1;
    			g.clear();
    			ad(i,j+1);
    			ad(i,j-1);
    			ad(i-1,j);
    			ad(i+1,j);
    			for (itr = g.begin(); itr != g.end(); itr++)
    				ans += sz[*itr];
    			s[i][j] = (char)(ans%10 + '0');
    		}
    for (i = 0; i < n; i++)
    	printf("%s\n",s[i]);
    return 0;
}