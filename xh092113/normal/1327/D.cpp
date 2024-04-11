#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 2e5;
const int inf = 0x3f3f3f3f;

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

int p[N+5],c[N+5];
bool vis[N+5];
int n;
int cn;
int idx[N+5];

vector<int>circle[N+5];
vector<int>fac[N+5];

int calc(vector<int>v){
	int n = v.size();
	for(rg int i = 0;i < fac[n].size();i++){
		int cur = fac[n][i];
//cout<<"n="<<n<<" cur="<<cur<<endl;
//		int t = n / cur;
		for(rg int j = 0;j < cur;j++){
			bool b = 1;
			if(c[v[j]] != c[v[(j+cur)%n]]){b = 0;continue;}
			for(rg int k = (j+cur) % n;k != j;k = (k+cur) % n)
				if(c[v[k]] != c[v[(k+cur)%n]]){
					b = 0;break;
				}
			if(b)return cur;
		}
	}
}

int main(){
//	freopen("D.in","r",stdin);
	int T = read();
	for(rg int i = 1;i <= N;i++){
		for(rg int j = i;j <= N;j += i)fac[j].push_back(i);
	}
	while(T--){
		n = read();
		cn = 0;
		memset(vis,0,sizeof(bool) * (n+1));
		memset(idx,0,sizeof(int) * (n+1));
		for(rg int i = 1;i <= n;i++)p[i] = read();
		for(rg int i = 1;i <= n;i++)c[i] = read();
		for(rg int i = 1;i <= n;i++){
			if(idx[i])continue;
			idx[i] = ++cn;
			circle[cn].resize(0);
			circle[cn].push_back(i);
			for(rg int j = p[i];j != i;j = p[j])idx[j] = cn,circle[cn].push_back(j);
		}
//for(rg int i = 1;i <= n;i++)cout<<idx[i]<<" ";cout<<endl;
		int ans = inf;
		for(rg int i = 1;i <= cn;i++)ans = min(ans,calc(circle[i]));
		write(ans),putchar('\n');
	}
	return 0;
}