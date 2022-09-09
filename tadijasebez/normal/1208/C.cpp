#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <deque>
#include <complex>
#include <tuple>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb double
#define mt make_tuple
void ckmn(int &a, int b){ a=min(a,b);}
void ckmn(ll &a, ll b){ a=min(a,b);}
void ckmx(int &a, int b){ a=max(a,b);}
void ckmx(ll &a, ll b){ a=max(a,b);}
int mod;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
const int N=1050;
int ans[N][N];
int main()
{
	int n,m=0;
	scanf("%i",&n);
	for(int i=0;i*4<n;i++)
	{
		for(int j=0;j*4<n;j++)
		{
			for(int x=i*4;x<i*4+4;x++)
			{
				for(int y=j*4;y<j*4+4;y++)
				{
					ans[x][y]=m++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%i ",ans[i][j]);
		printf("\n");
	}
	/*set<int> cnt;
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=0;j<n;j++) x^=ans[i][j];
		cnt.insert(x);
		x=0;
		for(int j=0;j<n;j++) x^=ans[j][i];
		cnt.insert(x);
	}
	if(cnt.size()!=1) printf("WRONG");
	else printf("CORRECT");*/
	return 0;
}