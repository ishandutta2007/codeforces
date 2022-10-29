#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 105;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int k;

int main(){
	//freopen("test.in","r",stdin);
	cin>>k;
	int b = (k + 2000 + 9e5) / 2000;
	int a = 2000 * b - 2000 - k;
	cout<<"2000\n";
	cout<<a<<" "<<-a<<" ";
	rep(i,3,1998) cout<<"0 ";
	cout<<"-1 "<<b<<endl;
	return 0;
}