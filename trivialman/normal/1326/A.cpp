#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 1e5+5;
mt19937 rng(time(0));

char s[N];
int n, T;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		s[1] = '8';
		rep(i,2,n) s[i] = '9';
		s[n+1] = '\0';
		cout<<(s+1)<<endl;
	}
	return 0;
}