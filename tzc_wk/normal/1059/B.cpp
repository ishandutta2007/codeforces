#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
char g[MAXN][MAXN];
int w[MAXN][MAXN];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			w[i][j]=1;
			if(g[i][j]=='.')	w[i][j]=2;
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			bool ok=true;
			for(int u=i-1;u<=i+1;u++){
				for(int v=j-1;v<=j+1;v++){
					if(u==i&&v==j)	continue;
					if(w[u][v]==2)	ok=false;
				}
			}
			if(ok){
				for(int u=i-1;u<=i+1;u++){
					for(int v=j-1;v<=j+1;v++){
						if(u==i&&v==j)	continue;
						w[u][v]=3;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(w[i][j]==1)	puts("NO"),exit(0);
		}
	}
	puts("YES");
	return 0;
}
 //