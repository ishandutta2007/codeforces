#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 110;

int n,m,h,a[N],b[N],c[N][N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>m>>n>>h;
	rep(i,1,n)cin>>b[i];
	rep(i,1,m)cin>>a[i];
	rep(i,1,m)rep(j,1,n)cin>>c[i][j];
	rep(i,1,m){
		rep(j,1,n)if(c[i][j]&&(a[i]<=b[j])){
			//cout<<i<<" "<<j<<" "<<a[i]<<endl;
			c[i][j]=a[i];break;
		}
	}
	rep(j,1,n){
		rep(i,1,m)if(c[i][j]&&(b[j]<=a[i])){
			c[i][j]=b[j];break;
		}
	} 
	rep(i,1,m){
		rep(j,1,n)cout<<c[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}