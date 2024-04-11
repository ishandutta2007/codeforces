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
int n,mn=0x3f3f3f3f;
char s[200005];
int sum[200005];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		if(s[i]==')')	sum[i]=sum[i-1]-1;
		else			sum[i]=sum[i-1]+1;
		mn=min(mn,sum[i]);
	}
	if(sum[n])	return puts("No"),0;
	if(mn<-1)	return puts("No"),0;
	puts("Yes");
	return 0;
}