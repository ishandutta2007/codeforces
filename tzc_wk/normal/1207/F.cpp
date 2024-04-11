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
int T;
const int B=314;
int sum[320][320];
int a[500005];
signed main(){
	cin>>T;
	while(T--){
		int opt;cin>>opt;
		if(opt==1){
			int x,y;
			cin>>x>>y;
			a[x]+=y;
			for(int i=1;i<=B;i++)
				sum[i][x%i]+=y;
		}
		else{
			int x,y;
			cin>>x>>y;
			if(x>B){
				int ans=0;
				for(int i=y;i<=500000;i+=x)
					ans+=a[i];
				printf("%I64d\n",ans);
			}
			else	printf("%I64d\n",sum[x][y]);
		}
	}
	return 0;
}