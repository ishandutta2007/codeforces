#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

ll su(ll a,ll b){
	a+=b;return (a>=M)?a-M:a;
}
int i,j,k,n,m,t,sb;
string s1,s2;
ll p[200500],res,cur;

int main() {
	p[0]=1;
	for(i=1;i<=200005;i++){
		p[i]=p[i-1]*2%M;
	}
	
	cin.tie(0);
	cin>>n>>m>>s1>>s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	s1="X"+s1;s2="X"+s2;
	for(i=m;i>=1;i--){
		cur+=s2[i]-'0';
		if(i<=n&&(s1[i]=='1')){
			res=su(res,p[i-1]*cur%M);
		}
	}
	cout<<res%M;
}