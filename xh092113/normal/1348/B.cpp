#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 100;

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

int n,k;
int a[N+5];
vector<int>b;
bool vis[N+5];

int main(){
//	freopen("B.in","r",stdin);
	int t = read();
	while(t--){
		memset(vis,0,sizeof(vis));
		n = read(),k = read();
		b.resize(0);
		for(rg int i = 1;i <= n;i++){
			a[i] = read();
			if(!vis[a[i]]){	
				vis[a[i]] = 1;b.push_back(a[i]);
			}
		}
		if(b.size() > k){
			puts("-1");
			continue;
		}
//for(auto x : b)cout<<x<<" ";cout<<endl;
		while(b.size() < k){
			int x = b[b.size()-1];
			b.push_back(x);
		}
		cout << n * k << endl;
		for(rg int i = 1;i <= n;i++){
			for(rg int j = 0;j < k;j++)write(b[j]),putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}