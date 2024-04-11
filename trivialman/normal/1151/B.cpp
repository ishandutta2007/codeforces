#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

int n,m,k,x,y;
int a[510][510],b[510];


int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>a[i][j];
	int ans = 0;
	rep(i,1,n)ans^=a[i][1];
	bool flag = true;
	rep(i,1,n)rep(j,1,m)if(a[i][j]!=a[i][1])flag=false;
	if(flag&&ans==0)cout<<"NIE\n";
	else{
		cout<<"TAK\n";
		rep(i,1,n)b[i]=1;
		if(ans==0){
			rep(i,1,n){
				rep(j,1,m)if(a[i][j]!=a[i][1]){
					b[i]=j;break;
				}
				if(b[i]!=1)break;
			}
		}
		rep(i,1,n)cout<<b[i]<<" ";
	}
	return 0;
}