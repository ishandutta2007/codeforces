#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			998244353
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
#define int long long
int n,a[100005];
int b[100005],c[100005];
int power(int x){
	int base=1;
	for(int i=1;i<=x;i++)	base=base*10%MOD;
	return base;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		while(a[i]){
			int dig=a[i]%10;
			b[i]=(dig*power(cnt*2)%MOD+b[i])%MOD;
			c[i]=(dig*power(cnt*2+1)%MOD+c[i])%MOD;
			a[i]/=10;
			cnt++;
		}
	}
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)	sum1=(sum1+b[i])%MOD;
	for(int i=1;i<=n;i++)	sum2=(sum2+c[i])%MOD;
	cout<<(sum1+sum2)%MOD*n%MOD<<endl;
	return 0;
}