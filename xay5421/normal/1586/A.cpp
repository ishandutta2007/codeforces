// author: xay5421
// created: Sun Oct 17 19:05:50 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int T,n,a[N],ban[N];
int main(){
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		for(int j=i+i;j<N;j+=i)ban[j]=1;
	}
	rd(T);
	while(T--){
		rd(n);
		int sum=0;
		rep(i,1,n)rd(a[i]),sum+=a[i];
		if(ban[sum]){
			printf("%d\n",n);
			rep(i,1,n)printf("%d ",i);
			puts("");
		}else{
			rep(i,1,n){
				if(ban[sum-a[i]]){
					printf("%d\n",n-1);
					rep(j,1,n)if(j!=i)printf("%d ",j);
					puts("");
					break;
				}
			}
		}
	}
	return 0;
}