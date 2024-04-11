#include<bits/stdc++.h>
using namespace std;

const int maxn=57;
int fg[maxn][maxn],n;

bool check(int a[]){
	if (a[1]!=a[6]) return 0;
	if (a[2]==a[5]||a[2]==a[3]||a[4]==a[5]) return 1;
	return 0;
}

bool query(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	cout.flush();
	bool x;
	cin>>x;
	return x;
}

bool valid1(int x,int y){
	if (x+1>n||y+2>n) return 0;
	int a[8],b[8];
	a[1]=b[1]=fg[x][y],a[2]=b[2]=fg[x][y+1],a[3]=b[3]=fg[x][y+2],a[4]=b[4]=fg[x+1][y],a[5]=b[5]=fg[x+1][y+1],a[6]=b[6]=fg[x+1][y+2];
	for (int i=1;i<=6;++i){
		if (abs(a[i])==2){
			a[i]/=2,b[i]/=-2;
		}
		bool fg1=check(a),fg2=check(b);
		if (fg1!=fg2){
			bool fg3=query(x,y,x+1,y+2);
			if (fg3==fg1){
				for (int i=1;i<=n;++i){
					for (int j=1;j<=n;++j){
						if (abs(fg[i][j])==2){
							fg[i][j]/=2;
						}
					}
				}
			}
			else{
				for (int i=1;i<=n;++i){
					for (int j=1;j<=n;++j){
						if (abs(fg[i][j])==2){
							fg[i][j]/=-2;
						}
					}
				}
			}
			return 1;
		} 
	}
}

bool valid2(int x,int y){
	if (x+2>n||y+1>n) return 0;
	int a[8],b[8];
	a[1]=b[1]=fg[x][y],a[2]=b[2]=fg[x+1][y],a[3]=b[3]=fg[x+2][y],a[4]=b[4]=fg[x][y+1],a[5]=b[5]=fg[x+1][y+1],a[6]=b[6]=fg[x+2][y+1];
	for (int i=1;i<=6;++i){
		if (abs(a[i])==2){
			a[i]/=2,b[i]/=-2;
		}
		bool fg1=check(a),fg2=check(b);
		if (fg1!=fg2){
			bool fg3=query(x,y,x+2,y+1);
			if (fg3==fg1){
				for (int i=1;i<=n;++i){
					for (int j=1;j<=n;++j){
						if (abs(fg[i][j])==2){
							fg[i][j]/=2;
						}
					}
				}
			}
			else{
				for (int i=1;i<=n;++i){
					for (int j=1;j<=n;++j){
						if (abs(fg[i][j])==2){
							fg[i][j]/=-2;
						}
					}
				}
			}
			return 1;
		} 
	}
}

void dfs(int u,int v){
	if (u+2<=n&&!fg[u+2][v]){
		if (query(u,v,u+2,v)){
			fg[u+2][v]=fg[u][v];
		}
		else{
			fg[u+2][v]=-fg[u][v];
		}
		dfs(u+2,v);
	}
	if (u+1<=n&&v+1<=n&&!fg[u+1][v+1]){
		if (query(u,v,u+1,v+1)){
			fg[u+1][v+1]=fg[u][v];
		}
		else{
			fg[u+1][v+1]=-fg[u][v]; 
		}
		dfs(u+1,v+1);
	}
	if (v+2<=n&&!fg[u][v+2]){
		if (query(u,v,u,v+2)){
			fg[u][v+2]=fg[u][v];
		}
		else{
			fg[u][v+2]=-fg[u][v];
		}
		dfs(u,v+2);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	memset(fg,0,sizeof(fg));
	fg[1][1]=1,fg[n][n]=-1;
	dfs(1,1);
	fg[1][2]=2;
	dfs(1,2);
	if (query(2,1,3,2)){
		fg[2][1]=fg[3][2];
	}
	else{
		fg[2][1]=-fg[3][2];
	}
	dfs(2,1);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (valid1(i,j)){
				cout<<"!"<<endl;
				for (int u=1;u<=n;++u){
					for (int v=1;v<=n;++v){
						cout<<(fg[u][v]+1)/2;
					}
					cout<<endl;
				}
				return 0;
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (valid2(i,j)){
				cout<<"!"<<endl;
				for (int u=1;u<=n;++u){
					for (int v=1;v<=n;++v){
						cout<<(fg[u][v]+1)/2;
					}
					cout<<endl;
				}
				return 0;
			}
		}
	}
}