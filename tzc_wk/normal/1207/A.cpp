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
int T;
int main(){
	cin>>T;
	while(T--){
		int b,p,f,h,c;cin>>b>>p>>f>>h>>c;
		int ans=0;
		for(int i=0;i<=min(p,b/2);i++){
			int sum=i*h;
			int bl=b-i*2;
			sum+=min(bl/2,f)*c;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}