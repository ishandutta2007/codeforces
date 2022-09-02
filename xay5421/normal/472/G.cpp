#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
char s[N],t[N];
int Q;
unsigned a[32][N/32+5],b[32][N/32+5];
int main(){
	scanf("%s%s%d",s,t,&Q);
	rep(j,0,31){
		for(int i=0;s[i+j];++i){
			a[j][i>>5]|=(s[i+j]=='1'?(1U<<(i&31)):0);
		}
		for(int i=0;t[i+j];++i){
			b[j][i>>5]|=(t[i+j]=='1'?(1U<<(i&31)):0);
		}
	}
	while(Q--){
		int p1,p2,len;
		rd(p1),rd(p2),rd(len);
		int ans=0,i,j;
		for(i=p1>>5,j=p2>>5;len>=32;++i,++j,len-=32)ans+=__builtin_popcount(a[p1&31][i]^b[p2&31][j]);
		ans+=__builtin_popcount((a[p1&31][i]^b[p2&31][j])&((1<<len)-1));
		pt(ans,'\n');
	}
	return 0;
}