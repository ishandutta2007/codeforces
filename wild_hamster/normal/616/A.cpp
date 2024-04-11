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
#define MOD 1000000000000037LL
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], inv[4000050],  pre[400050], dp[2200];

    char s[1000005], t[1000005];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%s", s);
    scanf("%s", t);
   	ll slen = strlen(s) ;
   	ll tlen = strlen(t) ;
   	string ss, tt;
   	i = 0;
   	while (i < slen && s[i] == '0')
   		i++;
   	ll sx = i;
   	i = 0;
   	while (i < tlen && t[i] == '0')
   		i++;
   	ll tx = i;
   	
   	//cout << sx << " " << slen << " " << tx << " " << tlen << endl;
   	if (sx == slen && tx == tlen)
   	{
   		cout << "=" << endl;
   		return 0;
   	}
   	if (sx == slen)
   	{
   		cout << "<" << endl;
   		return 0;
   	}
   	if (tx == tlen)
   	{
   		cout << ">" << endl;
   		return 0;
   	}
   	for (i = sx; i < slen; i++)
   		ss.push_back(s[i]);
   	for (i = tx; i < tlen; i++)
   		tt.push_back(t[i]);
   	if (ss.size() > tt.size())
   		cout << ">" << endl;
   	else
   	if (ss.size() < tt.size())
   		cout << "<" << endl;
   	else
   	if (ss < tt)
   		cout << "<" << endl;
   	else
   	if (ss > tt)
   		cout << ">" << endl;
   	else
   		cout << "=" << endl;
    return 0;
}