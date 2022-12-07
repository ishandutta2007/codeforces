#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 10;

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

int p[6],q[6];
int x,y;

int main(){
	x = read();
	for(rg int i = 0;i < 6;i++)p[i] = (bool)(x & (1 << i));
	q[5] = p[4];
	q[4] = p[1];
	q[3] = p[3];
	q[2] = p[2];
	q[1] = p[0];
	q[0] = p[5];
	for(rg int i = 0;i < 5 - i;i++)swap(q[i],q[5-i]);
	for(rg int i = 0;i < 6;i++)y += (q[i] << i);
	cout<<y<<endl;
	return 0;
}