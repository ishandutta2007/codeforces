#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int h,m;
int idx[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};

void Inc(int &curh,int &curm){
	curm++;
	if(curm == m)curm = 0,curh++;
	if(curh == h)curh = 0;
}
In bool check(int curh,int curm){
	int x = curh / 10,y = curh % 10,z = curm / 10,w = curm % 10;
	x = idx[x],y = idx[y],z = idx[z],w = idx[w];
	if(x == -1 || y == -1 || z == -1 || w == -1)return 0;
	int newh = w * 10 + z,newm = y * 10 + x;
	return 0 <= newh && newh < h && 0 <= newm && newm < m;
}
void print(int x){
	putchar(x / 10 + '0');putchar(x % 10 + '0');
}
void solve(){
	h = read(),m = read();
	int curh = read(),curm = read();
	while(!check(curh,curm))Inc(curh,curm);
	print(curh),putchar(':'),print(curm),putchar('\n');
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}