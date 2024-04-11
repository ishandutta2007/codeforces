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
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=4050;
vector<int> ans;
char s[N],t[N];
bool OK(int n)
{
	int OO=0,OX=0,XO=0,XX=0;
	for(int i=2;i<=n;i+=2)
	{
		if(s[i-1]=='0' && s[i]=='0') OO++;
		if(s[i-1]=='0' && s[i]=='1') OX++;
		if(s[i-1]=='1' && s[i]=='0') XO++;
		if(s[i-1]=='1' && s[i]=='1') XX++;
		if(t[i-1]=='0' && t[i]=='0') OO--;
		if(t[i-1]=='0' && t[i]=='1') XO--;
		if(t[i-1]=='1' && t[i]=='0') OX--;
		if(t[i-1]=='1' && t[i]=='1') XX--;
	}
	if(OO==0 && OX==0 && XO==0 && XX==0) return 1;
	return 0;
}
void Find(int n, int add=-1)
{
	//printf("%s\n",t+1);
	//printf("%s\n",s+1);
	int used=0;
	for(int i=n;i>=2;i-=2)
	{
		for(int j=used+2;j<=n;j+=2)
		{
			if(t[i]==s[j-1] && t[i-1]==s[j])
			{
				if(j!=2)
				{
					ans.pb(j-2);
					reverse(s+1,s+1+j-2);
					//printf("%s\n",s+1);
				}
				ans.pb(j);
				reverse(s+1,s+1+j);
				//printf("%s\n",s+1);
				break;
			}
			assert(j!=n);
		}
		used+=2;
	}
	if(add!=-1) ans.pb(add);
	printf("%i\n",ans.size());
	for(int a:ans) printf("%i ",a);
	printf("\n");
}
void Solve(int n)
{
	int OO=0,XX=0;
	for(int i=2;i<=n;i+=2)
	{
		if(s[i-1]=='0' && s[i]=='0') OO++;
		if(s[i-1]=='1' && s[i]=='1') XX++;
		if(t[i-1]=='0' && t[i]=='0') OO--;
		if(t[i-1]=='1' && t[i]=='1') XX--;
	}
	if(OO!=0 || XX!=0)
	{
		printf("-1\n");
		return;
	}
	ans.clear();
	if(OK(n)){ Find(n);return;}
	for(int i=2;i<=n;i+=2)
	{
		reverse(s+1,s+1+i);
		if(OK(n)){ ans.pb(i);Find(n);return;}
		reverse(s+1,s+1+i);
	}
	for(int i=2;i<=n;i+=2)
	{
		reverse(t+1,t+1+i);
		if(OK(n)){ Find(n,i);return;}
		reverse(t+1,t+1+i);
	}
	assert(0);
	//printf("-1\n");
}
int main()
{
	int q;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n=strlen(s+1);
		Solve(n);
	}
	return 0;
}