#include<bits/stdc++.h>
using namespace std;

const int maxn=57;
int n,m,mp[maxn][maxn],cnt=0;
int B[maxn][maxn];
int ansx[maxn*maxn],ansy[maxn*maxn];

bool ck(int u,int v){
	for (int i=0;i<2;++i){
		for (int j=0;j<2;++j){
			if (mp[u+i][v+j]==0) return 0;
		} 
	}
	for (int i=0;i<2;++i){
		for (int j=0;j<2;++j){
			B[u+i][v+j]=1;
		} 
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(B,0,sizeof(B));
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			cin>>mp[i][j];
		}
	}
	for (int i=1;i<n;++i){
		for (int j=1;j<m;++j){
			if (ck(i,j)){
				ansx[++cnt]=i,ansy[cnt]=j;
			}
		}
	}
	
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			if (B[i][j]!=mp[i][j]){
				puts("-1");
				return 0;
			}
		}
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;++i){
		cout<<ansx[i]<<" "<<ansy[i]<<endl;
	}
	return 0;
}