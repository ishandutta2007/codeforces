#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e4+5;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T, n, x, y; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=3)
			cout<<"-1\n";
		else{
			x = n%2 ? n : n-1, y = 2*n-1-x;
			for(int i=x;i>=1;i-=2) cout<<i<<" ";
			cout<<"4 2 ";
			for(int i=6;i<=y;i+=2) cout<<i<<" ";
			cout<<endl;
		}
	}
	return 0;
}