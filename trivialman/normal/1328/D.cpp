#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int T, n;
int a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",a+i);
		int nseg = 0;
		rep(i,2,n) if(a[i]!=a[i-1]) nseg++;
		if(a[n]!=a[1])nseg++;
		
		if(nseg==0){
			printf("1\n");
			rep(i,1,n) printf("1 ");
			printf("\n");
		}else if(nseg==n){
			printf(n%2?"3\n":"2\n");
			rep(i,1,n-1) printf("%d ",2-i%2);
			printf("%d\n", n%2+2);
		}else{
			bool rev = nseg % 2;
			int x = 1;
			printf("2\n");
			rep(i,1,n){
				printf("%d ",x);
				if(a[i]==a[i+1]){
					if(rev) x = 3 - x, rev = false;
				}else x = 3 - x;
			}
			printf("\n");
		}
	}
	
	return 0;
}