#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 200;

typedef pair<int,int>pii;

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

int vis[N+5];

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int t = read();
	while(t--){
		int n = read(),x = read();
		memset(vis,0,sizeof(vis));
		for(rg int i = 1;i <= n;i++)vis[read()] = 1;
		int cur = 1;
		for(rg int i = 1;i <= x;i++){
			for(;vis[cur];cur++);
			vis[cur] = 1;			
		}
		for(;vis[cur];cur++);
		write(cur - 1),putchar('\n');
	}
	return 0;
}