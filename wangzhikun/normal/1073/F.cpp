#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}
int n,u,v,ax1,ax2,ay1,ay2,a1 = 0,a2 = 0;
vector<int> G[200010];
int x1[200020],x2[200020],idist[200020],bdist[200020];
void dfs(int num,int fa = -1){
	//cout<<num<<endl;
	idist[num] = 0;bdist[num] = -1;
	x1[num] = num;x2[num] = -1;
	int cx1 = -1,cx2 = -1,cd1 = 0,cd2 = 0;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num);
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		if(bdist[ct] == -1){
			if(bdist[num] == -1 && idist[ct]>=idist[num]){
				x1[num] = x1[ct];
				idist[num] = idist[ct]+1;
			}
			if(idist[ct]>=cd2){
				if(idist[ct]>=cd1){
					cd2 = cd1;
					cx2 = cx1;
					cd1 = idist[ct]+1;
					cx1 = x1[ct];
				}else{
					cd2 = idist[ct]+1;
					cx2 = x1[ct];
				}
			}
		}
	}
	if(cx1!=-1 && cx2!=-1){
		bdist[num] = 0;
		idist[num] = cd1+cd2;
		x1[num] = cx1;x2[num] = cx2;
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		if(bdist[ct]!=-1){
			if(bdist[num]!=-1)if(bdist[num]+bdist[ct]+2>a1 || (bdist[num]+bdist[ct]+2 == a1 && idist[ct]+idist[num]>a2)){
				a1 = bdist[num]+bdist[ct]+2;
				a2 = idist[ct]+idist[num];
				ax1 = x1[num];ax2 = x2[num];
				ay1 = x1[ct];ay2 = x2[ct];
			}
			if(bdist[ct]>=bdist[num] || (bdist[ct] == bdist[num]-1 && idist[ct]>idist[num])){
				bdist[num] = bdist[ct]+1;
				idist[num] = idist[ct];
				x2[num] = x2[ct];
				x1[num] = x1[ct];
			}
		}
	}
}
int main() {
	srand(19260817);
	cin>>n;
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(G[i].size()>=3){
			dfs(i);
			break;
		}
	}
	cout<<ax1<<' '<<ay1<<'\n'<<ax2<<' '<<ay2<<endl;
	return 0;
}