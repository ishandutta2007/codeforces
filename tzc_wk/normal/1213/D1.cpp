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
int n,k,a[200005],x[55],ans=0x3f3f3f3f;
map<pair<int,int>,int> mp;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int tmp=a[i],cnt=0;
		while(tmp){
			mp[make_pair(i,tmp)]=cnt;
			cnt++;
			tmp/=2;
		}
		mp[make_pair(i,0)]=cnt;
	}
//	cout<<"ok";
	for(int i=0;i<=200000;i++){
		memset(x,0,sizeof(x));
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(!mp.count(make_pair(j,i)))	x[j]=0x3f3f3f3f;
			else							x[j]=mp[make_pair(j,i)];
		}
		sort(x+1,x+n+1);
		int sum=0;
		for(int j=1;j<=k;j++)	sum+=x[j];
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}