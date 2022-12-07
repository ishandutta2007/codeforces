#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1e5;

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
/*
int match[N+5];
bool vis[N+5];
vector<int>link[N+5];
vector<int>s;

bool dfs(int u){
	for(rg int i = 0;i < link[u].size();i++){
		int v = link[u][i];
		if(!vis[v]){
			vis[v] = 1;
			s.push_back(v);
			if(!match[v] || dfs(match[v])){
				match[v] = u;
				return 1;
			}	
		}
	}
	return 0;
}

bool ok[N+5];
*/

vector<int>link[N+5];
bool match[N+5];
int choice[N+5];

int main(){
//	freopen("B.in","r",stdin);
	int t = read();
	while(t--){
		int n = read();
		for(rg int i = 1;i <= n;i++){
			link[i].resize(0);
			int p = read();
			for(rg int j = 1;j <= p;j++){
				int x = read();
				link[i].push_back(x);
			}
		}
		for(rg int i = 1;i <= n;i++){
			for(rg int j = 0;j < link[i].size();j++)if(!match[link[i][j]]){
				match[link[i][j]] = 1;
				choice[i] = link[i][j];
				break;
			}
		}
//for(rg int i = 1;i <= n;i++)cout<<choice[i]<<" ";cout<<endl;
		int b = 1;
		for(rg int i = 1;i <= n;i++){
			if(!choice[i]){
				b = 0;
				puts("IMPROVE");
				for(rg int j = 1;j <= n;j++)if(!match[j]){
					write(i),putchar(' '),write(j),putchar('\n');
					break;
				}
				break;
			}
		}
		if(b)puts("OPTIMAL");
		memset(match,0,sizeof(bool) * (n+1));
		memset(choice,0,sizeof(int) * (n+1));
	}
	return 0;	
}