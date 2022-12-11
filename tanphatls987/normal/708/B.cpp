#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=0;

ll a00,a01,a10,a11;

string solve(){
	///both equal 0
	if (a00==0&&a11==0){
		if (a01==0&&a10==0) return "1";
		if (a01==1&&a10==0) return "01";
		if (a10==1&&a01==0) return "10";
		return "Impossible";
	}
	///cal n0 n1
	ll n0=ll(sqrt(2*a00));
	while (n0*(n0-1)/2<a00) n0++;
	if (n0*(n0-1)/2!=a00) return "Impossible";
	ll n1=ll(sqrt(2*a11));
	while (n1*(n1-1)/2<a11) n1++;
	if (n1*(n1-1)/2!=a11) return "Impossible";
	
	// cout<<n0<<" "<<n1<<'\n';
	if (a00==0){
		if (a01==0){
			string ans(n1,'1');
			if (a10==0) return ans;
			if (a10!=n1) return "Impossible";
			ans.push_back('0');
			return ans;
		}
		if (a01+a10!=n1) return "Impossible";
		string ans=string(a10,'1')+'0'+string(a01,'1');
		return ans;
	}
	if (a11==0){
		if (a10==0){
			string ans(n0,'0');
			if (a01==0) return ans;
			if (a01!=n0) return "Impossible";
			ans.push_back('1');
			return ans;
		}
		if (a01+a10!=n0) return "Impossible";
		string ans=string(a01,'0')+'1'+string(a10,'0');
		return ans;
	}
	///usual case
	if (a01+a10!=n0*n1) return "Impossible";
	string ans;
	while (n0||n1){
		if (a01>=n1) ans.push_back('0'),a01-=n1,n0--;
		else ans.push_back('1'),n1--;
	}
	return ans;
}
int main(){
	cin>>a00>>a01>>a10>>a11;
	cout<<solve();
}