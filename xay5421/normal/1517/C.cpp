// author: xay5421
// created: Fri Apr 23 22:52:13 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,a[505],b[505][505];
int rem;
void ps(int x,int y,int v){
	if(!rem||b[x][y])return;
	if(x>=1&&x<=n&&y>=1&&y<=x){
		b[x][y]=v;
		--rem;
		ps(x-1,y,v);
		ps(x,y-1,v);
		ps(x+1,y,v);
		ps(x,y+1,v);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		rem=a[i];
		ps(i,i,a[i]);
	}
	rep(i,1,n)rep(j,1,i)pt(b[i][j],j==i?'\n':' ');
	return 0;
}