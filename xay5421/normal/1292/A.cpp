#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,Q,a[3][N];
int count(int k1,int i){
	if(k1==1){
		return a[2][i-1]+a[2][i]+a[2][i+1];
	}else return a[1][i-1]+a[1][i]+a[1][i+1];
}
signed main(){
	rd(n),rd(Q);
	int ans=0;
	while(Q--){
		int k1,k2;rd(k1),rd(k2);
		if(a[k1][k2]==0)ans+=count(k1,k2);
		else ans-=count(k1,k2);
		a[k1][k2]^=1;
		if(ans==0)puts("Yes");else puts("No");
	}
	return 0;
}