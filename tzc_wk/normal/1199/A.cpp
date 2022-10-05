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
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
int n,x,y,a[100011];
int main(){
	cin>>n>>x>>y;
	REP(i,n)	cin>>a[i];
	for(int i=n+1;i<=n+10;i++)	a[i]=INT_MAX;
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=i-1;j>=i-x;j--)	if((a[i]>=a[j]&&j<=n&&j>=1))		flag=0;
		for(int j=i+1;j<=i+y;j++)	if((a[i]>=a[j]&&j<=n&&j>=1))	flag=0;
		if(flag){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}//