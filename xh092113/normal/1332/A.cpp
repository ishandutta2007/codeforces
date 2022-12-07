#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

In bool check(int x,int l,int r,int ln,int rn){
	int last = x + rn - ln;
	if(last < l || last > r)return 0;
	if(l == r){
		if(ln || rn)return 0;
		return 1;
	}
	return 1;
}

int x,y,xl,yl,xr,yr,a,b,c,d;

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int t = read();
	while(t--){
		a = read(),b = read(),c = read(),d = read();
		x = read(),y = read(),xl = read(),yl = read(),xr = read(),yr = read();
		if(check(x,xl,xr,a,b) && check(y,yl,yr,c,d))puts("Yes");
		else puts("No");
	}
	return 0;
}