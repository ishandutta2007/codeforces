#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1200;
mt19937 rng(time(0));

int x,y;
int C[N][N];


int main() {
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>x>>y;
	C[0][0] = 1;
	rep(i,1,N-1){
		C[i][0] = C[i][i] = 1;
		rep(j,1,i-1) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % P;
	}
	cout<<C[2*y+x-1][x-1]<<endl;
	return 0;
}