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
const int N=200050;
char s[N];
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	scanf("%s",s);
	bool ok=1;
	for(int i=k;i<n;i++)
	{
		if(s[i]>s[i%k]) ok=0;
		if(s[i]<s[i%k]) break;
	}
	if(ok)
	{
		printf("%i\n",n);
		for(int i=0;i<n;i++) printf("%c",s[i%k]);
		printf("\n");
	}
	else
	{
		int ptr=k-1;
		while(ptr>=0 && s[ptr]=='9') s[ptr]='0',ptr--;
		if(ptr==-1)
		{
			printf("%i\n",n+1);
			for(int i=0;i<=n;i++) printf("%i",i%k==0?1:0);
			printf("\n");
		}
		else
		{
			s[ptr]++;
			printf("%i\n",n);
			for(int i=0;i<n;i++) printf("%c",s[i%k]);
			printf("\n");
		}
	}
	return 0;
}