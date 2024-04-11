#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T,a,b,c;

int main(){
	//freopen("test.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		if(a>b+c){
			cout<<c+1<<endl;
		}else if(a+c<=b){
			cout<<0<<endl;
		}else{
			cout<<a+c-(a+b+c)/2<<endl;
		}
	}
	return 0;
}