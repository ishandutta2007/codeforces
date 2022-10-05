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
string s[50004];
int cnt1[50004],cnt2[50004];
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.ans","w",stdout);
	DR1(T);
	while(T--){
		DR2(n,m);
		for(int i=0;i<=n+1;i++)	cnt1[i]=0;
		for(int i=0;i<=m+1;i++)	cnt2[i]=0;
		REP(i,n)	cin>>s[i],s[i]=" "+s[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(s[i][j]=='*')
					cnt1[i]++;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++)
				if(s[j][i]=='*')
					cnt2[i]++;
		}
		int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans=min(ans,max(n+m-cnt1[i]-cnt2[j]+((s[i][j]=='.')?-1:0),0));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}