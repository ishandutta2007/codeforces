#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

int n,cnt=0;
char a[510][510];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)for(int j=n;j;--j)a[i][j]=a[i][j-1];
	rep(i,1,n)a[i][0]='.';
	rep(i,1,n)rep(j,1,n){
		if(a[i][j]=='X'&&a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j-1]=='X'&&a[i+1][j+1]=='X')++cnt;
	}
	cout<<cnt<<endl;
	return 0;
}