#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> z_algorithm(string &s){
	int n=s.size();
	vector<int> ret(n);
	ret[0]=s.size();
	int i=1, j=0;
	while(i<n){
		while(i+j<n&&s[j]==s[i+j])++j;
		ret[i]=j;
		if(j==0){
			++i;
			continue;
		}
		int k=1;
		while(i+k<n&&k+ret[k]<j)ret[i+k]=ret[k], ++k;
		i+=k;
		j-=k;
	}
	return ret;
}

int solve(string& t){
	auto ret=z_algorithm(t);
	int n=t.size();
	rep(i,n-1){
		if(ret[i+1]+i+1==n)return i+1;
	}
	return n;
}

int main(){
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	int res=solve(t);
	string u=t.substr((m/res)*res);
	t=t.substr(0,res);
	//cout<<t<<endl;
	m=t.size();
	int cnt1=0,cnt2=0;
	rep(i,n)cnt1+=(s[i]=='1');
	rep(i,m)cnt2+=(t[i]=='1');
	if(n<m){
		cout<<s<<endl;
		return 0;
	}
	int num=n/m;
	int ok=0;
	rep(i,num+1){
		if(cnt2*i<=cnt1&&cnt2*i+n-m*i>=cnt1)ok=i;
	}
	string ans="";
	rep(i,ok){
		ans+=t;
		cnt1-=cnt2;
		n-=m;
	}
	int cnt3=0;
	rep(i,u.size())cnt3+=(u[i]=='1');
	if(u.size()<=n&&cnt3<=cnt1&&u.size()-cnt3<=n-cnt1){
		ans+=u;
		n-=u.size();
		cnt1-=cnt3;
	}
	rep(i,cnt1){
		ans+='1';
		--n;
	}
	rep(i,n)ans+='0';
	cout<<ans<<endl;

	return 0;
}