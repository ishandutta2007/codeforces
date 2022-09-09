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

int main(){
	int n;
	scanf("%i",&n);
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)scanf("%i",&a[i].first);
	for(int i=0;i<n;i++)scanf("%i",&a[i].second);
	int ptr=0;
	multiset<int> all;
	ll sum=0,ans=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		int cur=a[i].first;
		int mx=i+1==n?2e9:a[i+1].first;
		all.insert(a[i].second);
		sum+=a[i].second;
		while(cur<mx && all.size()){
			int mao=*all.rbegin();
			all.erase(--all.end());
			sum-=mao;
			ans+=sum;
			cur++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}