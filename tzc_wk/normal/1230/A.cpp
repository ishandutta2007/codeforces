#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
int a[5];
int main(){
	REP(i,4)	cin>>a[i];
	sort(a+1,a+5);
	if(a[1]+a[4]==a[2]+a[3]||a[1]+a[2]+a[3]==a[4])	puts("YES");
	else											puts("NO");
	return 0;
}