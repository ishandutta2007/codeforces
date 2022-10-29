#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 510;

LL m,n,x,a[N][N],s[N],ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>m>>n;
	rep(i,1,m)rep(j,1,n)cin>>a[i][j];
	rep(i,1,m)rep(j,1,n){
		cin>>x;
		a[i][j]^=x;
	} 
	bool flag = true;
	memset(s,0,sizeof s);
	rep(i,1,m)rep(j,1,n)s[i]+=a[i][j];
	rep(i,1,m)if(s[i]&1)flag = false;
	memset(s,0,sizeof s);
	rep(i,1,m)rep(j,1,n)s[j]+=a[i][j];
	rep(i,1,n)if(s[i]&1)flag = false;
	cout<<(flag?"Yes":"No")<<endl;
	return 0;
}