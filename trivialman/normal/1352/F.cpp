#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 1000;
const int INF = (1<<30)-1;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, a, b, c;
char s[N];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>a>>c>>b;
		if(b+c==0){
			rep(i,1,a+1) s[i]='0';
		}else if(a+c==0){
			rep(i,1,b+1) s[i]='1';
		}else{
			rep(i,1,a+1) s[i]='0';
			rep(i,a+2,a+b+2) s[i]='1';
			rep(i,a+b+3,a+b+c+1) s[i]='0'+'1'-s[i-1];
		}
		s[a+b+c+2]=0;
		cout<<(s+1)<<endl;
	}
	return 0;
}