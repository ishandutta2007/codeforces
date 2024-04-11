//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n;
vector<int> tv;
int lst[1310000][26];
bool vis[1310000];
int main(){
	read(n);
	int tsu = 0;
	int cu;
	for(int i=0;i<n*2;i++){
		read(cu);
		tsu+=cu;
		tv.push_back(cu);
	}
	sort(tv.begin(),tv.end());
	int ans = 1e9,rans[30][2];
	int csz = 0;
	for(int j=n*2-1;j>=n+1;j--)csz+=tv[j];
	for(int j=0;j<=csz;j++)memset(lst[j],0,sizeof(lst[j]));
	//cout<<csz<<endl;
	memset(vis,0,sizeof(vis));
	lst[0][0] = 99999;
	vis[0] = 1;
	int used[100] = {0};
	for(int i=1;i>=1;i--){
		//cout<<"Cur Pos "<<i<<endl;
		int sua = 0,sub = 0;
		for(int j=0;j<i;j++)sua+=tv[j];
		sub+=tv[i];
		for(int j= n*2-1;j>=i+1;j--){
			if(used[j])continue;
			used[j]=1;
			int cv = tv[j];
			for(int k=csz;k>=cv;k--){
				if(!vis[k-cv])continue;
				for(int l=n;l>=1;l--){
					if(lst[k-cv][l-1]!=0&& lst[k][l] == 0){
						lst[k][l] = j;
						vis[k] = 1;
					}
				}
			}
		}
		int cans = 1e9,cbst = 0;
		debug(i);
		for(int j=0;j<=csz;j++){
			if(lst[j][n-i]){
				if(max(j+sua+sub,tsu-sua-sub-j+sub+tv[0])<cans){
					cans = max(j+sua+sub,tsu-sua-sub-j+sub+tv[0]);
					cbst = j;
				}
			}
		}
		//cout<<"Cans "<<i<<' '<<cans<<endl;
		if(cans<ans){
			vector<int> ntv = tv;
			ans = cans;
			for(int j=0;j<i;j++){
				rans[j][0] = ntv[j];
				ntv[j] = -1;
			}
			int cp = cbst,cn = n-i;
			for(int j = i;j<n;j++){
				rans[j][0] = ntv[lst[cp][cn]];
				ntv[lst[cp][cn]] = -1;
				cp-=rans[j][0];
				cn--;
			}
			int p = n-1;
			for(int j=0;j<2*n;j++){
				if(ntv[j]!=-1){
					rans[p][1] = ntv[j];
					p--;
				}
			}
		}
	}
	//cout<<ans<<endl;
	for(int i=0;i<n;i++)cout<<rans[i][0]<<' ';
	cout<<endl;
	for(int i=0;i<n;i++)cout<<rans[i][1]<<' ';
	cout<<endl;
	return 0;
}