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
int T,a[100005],sum[100005],n,ans; 
int main(){
	cin>>T;
	while(T--){
		memset(sum,0,sizeof(sum));
		cin>>n;
		int num=0;
		for(int i=1;i<=n;i++)	cin>>a[i],sum[a[i]]++;
		for(int i=0;i<=100000;i++){
			num+=sum[i];
			if(n-num>=2&&n-2>=i)	ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}