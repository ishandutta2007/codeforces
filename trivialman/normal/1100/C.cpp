#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+10;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
double r;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>r;
	cout<<setprecision(10)<<fixed<<r*sin(pi/n)/(1-sin(pi/n))<<endl;
	return 0;
}