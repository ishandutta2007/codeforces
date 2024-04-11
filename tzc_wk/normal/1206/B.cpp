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
#define int long long
int n,a[100005],cnt,ans;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int dist1=abs(-1-a[i]);
		int dist2=abs(1-a[i]);
		if(dist1<dist2){
			cnt++;
			ans+=dist1;
		}
		else{
			ans+=dist2;
		}
	}
	if(cnt%2==0){
		cout<<ans<<endl;
	}
	else{
		int mn=LLONG_MAX;
		for(int i=1;i<=n;i++){
			int dist1=abs(-1-a[i]);
			int dist2=abs(1-a[i]);
			if(dist1<=dist2){
				mn=min(mn,dist2-dist1);
			}
		}
		cout<<ans+mn<<endl;
	}
	return 0;
}