#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int P = 998244353;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int k;
char s[15];

int get(){
	cin>>k;
	rep(i,1,k)cin>>s;
	return k;
}

int main(){
	//freopen("test.in","r",stdin);
	while(true){
		cout<<"next 0 1\n"<<flush;
		get();
		cout<<"next 0\n"<<flush;
		int k = get();
		if(k==2) break;
	}
	while(true){
		cout<<"next 0 1 2 3 4 5 6 7 8 9\n"<<flush;
		int k = get();
		if(k==1) break;
	}
	cout<<"done\n";
	return 0;
}