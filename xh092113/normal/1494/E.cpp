#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;

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
}
using namespace IO;

map<int,char> Mp[N+5];
int b0,b1,n,q;

void check(int u,int v,char c,int opt){
	if(Mp[v].count(u)){
		b1 += opt;
		if(Mp[v][u] == c)b0 += opt;
	}
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	n = read(),q = read();
	for(rg int i = 1;i <= q;i++){
		char ch = getchar();
		while(ch != '+' && ch != '-' && ch != '?')ch = getchar();
		if(ch == '+'){
			int u = read(),v = read();
			char c = getchar();
			while(c < 'a' || c > 'z')c = getchar();
			check(u,v,c,1);
			Mp[u][v] = c;
		}
		else if(ch == '-'){
			int u = read(),v = read();
			char c = Mp[u][v];
			check(u,v,c,-1);
			Mp[u].erase(v);
		}
		else{
			int k = read();
//cout<<"b0="<<b0<<" b1="<<b1<<endl;
			if(k & 1){
				if(b1)puts("YES");else puts("NO");
			}
			else{
				if(b0)puts("YES");else puts("NO");
			}
		}
	}
	return 0;
}