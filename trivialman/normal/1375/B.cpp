#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 305;
mt19937 rng(time(0));

int T, n, m;
int a[N][N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) rep(j,1,m) scanf("%d",a[i]+j);
		
		bool flag = true;
		rep(i,1,n) rep(j,1,m){
			bool fi = i==1 || i==n;
			bool fj = j==1 || j==m;
			if (fi&&fj) {
				if(a[i][j]>2) flag = false;
				else a[i][j] = 2;
			}else if(fi||fj) {
				if(a[i][j]>3) flag = false;
				else a[i][j] = 3;
			}else{
				if(a[i][j]>4) flag = false;
				else a[i][j] = 4;
			}
		}
		
		if(!flag){
			printf("NO\n");
		}else{
			printf("YES\n");
			rep(i,1,n) rep(j,1,m)
				printf("%d%c",a[i][j],j==m?'\n':' ');
		}
	}
	return 0;
}