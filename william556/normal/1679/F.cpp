#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline void Add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int n,m;
bool mp[10][10];
int f[2][1<<10];
int to[1<<10][10];
int main(){
	cin>>n;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		mp[x][y]=mp[y][x]=1;
	}
	f[0][0]=1;
	for(int s=0;s<1<<10;s++){
		for(int i=0;i<10;i++){
			if(s&(1<<i)){
				to[s][i]=-1;
				continue;
			}
			for(int j=0;j<10;j++){
				if(!mp[i][j])continue;
				if(j>i||s&(1<<j))to[s][i]|=1<<j;
			}
		}
	}
	int p=0;
	for(int i=1;i<=n;i++,p^=1){
		for(int s=0;s<1<<10;s++){
			if(!f[p][s])continue;
			for(int i=0;i<10;i++){
				int t=to[s][i];
				if(t!=-1)Add(f[p^1][t],f[p][s]);
			}
			f[p][s]=0;
		}
	}
	int ans=0;
	for(int s=0;s<1<<10;s++)Add(ans,f[p][s]);
	cout<<ans;
	return 0;
}