#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=105;
char base[N][N];
int my[N],ans[N][N];
char GetChar(int i)
{
	if(i<=26) return 'a'+(i-1);
	if(i<=52) return 'A'+(i-27);
	if(i<=62) return '0'+(i-53);
}
void Run()
{
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%s",base[i]+1);
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum+=base[i][j]=='R';
	queue<pair<int,int>> polja;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=m;j++) polja.push({i,j});
		}
		else
		{
			for(int j=m;j>=1;j--) polja.push({i,j});
		}
	}
	for(int i=1;i<=k;i++)
	{
		my[i]=sum/k;
		if(i<=sum%k) my[i]++;
		while(my[i])
		{
			assert(polja.size());
			int x,y;tie(x,y)=polja.front();
			polja.pop();
			ans[x][y]=i;
			if(base[x][y]=='R') my[i]--;
		}
	}
	while(polja.size())
	{
		int x,y;tie(x,y)=polja.front();
		polja.pop();
		ans[x][y]=k;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%c",GetChar(ans[i][j]));
		}
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--) Run();
	return 0;
}