#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli mod=1e9+7;

pll arr[100000];
int n;
char str[100001];

int main() {
	scanf("%d",&n);
	
	lli ans=0;
	for(int i=0;i<n;i++) {
		scanf("%s",str);

		int l=strlen(str),c=0;
		for(int j=0;j<l;j++) {
			if(str[j]=='s') arr[i].first++,c++;
			else arr[i].second++,ans += c;
		}
	}
	sort(arr,arr+n,[](const pll &a,const pll &b) {
		if(a.first==0) {
			if(b.first!=0) return false;
			else return a.second < b.second;
		}
		else if(a.second == 0) {
			if(b.second!=0) return true;
			else return a.first < b.first;
		}
		return a.second*b.first < a.first*b.second;
	});

	int c=0;
	for(int i=0;i<n;i++) {
		ans = ans + c * arr[i].second;
		c += arr[i].first;
	}
	printf("%lld\n",ans);
	

	return 0;
}