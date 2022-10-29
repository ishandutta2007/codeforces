#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	if(n%2==0)cout<<"NO\n";
	else{
		printf("YES\n");
		rep(i,1,n)printf("%d ",i*2-i%2);
		rep(i,1,n)printf("%d ",i*2+i%2-1);
	} 
	return 0;
}