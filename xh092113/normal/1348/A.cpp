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

int main(){
//	freopen("A.in","r",stdin);
	int t = read();
	while(t--){
		int n = read(),m = n >> 1;
		int A = 0,B = 0;
		for(rg int i = 1;i < m;i++)A += (1 << i);
		for(rg int i = m;i < n;i++)B += (1 << i);
		A += (1 << n);
		cout << A - B << endl;	
	}
	return 0;
}