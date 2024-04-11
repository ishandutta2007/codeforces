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
string s,t;
int main(){
	cin>>T;
	while(T--){
		cin>>s>>t;
		int ind=-1;
		for(int i=t.size()-1,cnt=0;i>=0;i--,cnt++){
			if(t[i]=='1'){
				ind=cnt;
				break;
			}
		}
//		cout<<ind<<endl;
		if(ind==-1){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=s.size()-ind-1;i>=0;i--){
			if(s[i]=='0'){
				ans++;
			}
			else	break;
		}
		cout<<ans<<endl;
	}
	return 0;
}