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
ll ans[26][26];
int cnt[26];
const int N=200050;
char s[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)
			ans[j][s[i]-'a']+=cnt[j];
		cnt[s[i]-'a']++;
	}
	ll sol=0;
	for(int i=0;i<26;i++)ckmx(sol,(ll)cnt[i]);
	for(int i=0;i<26;i++)for(int j=0;j<26;j++)ckmx(sol,ans[i][j]);
	printf("%lld\n",sol);
	return 0;
}