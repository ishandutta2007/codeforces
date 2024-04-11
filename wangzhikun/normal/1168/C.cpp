#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,q;
int a[600030],cgt[20][40][40],ans[600030];
vector< pair<int,int> > que[600030];
int main() {
	read(n);read(q);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	int cur = 0;
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++){
			cgt[cur][i][j] = n;
		}
	for(int e=0;e<q;e++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		que[x].push_back(make_pair(y,e));
	}
	int gto[20];
	for(int po=n-1;po>=0;po--){
		cur^=1;
		memcpy(cgt[cur],cgt[cur^1],sizeof(cgt[cur]));
		
		for(int i=0;i<19;i++)gto[i] = n;
		for(int i=0;i<19;i++){
			if((a[po]>>i)&1){
				for(int j=0;j<19;j++)gto[j] = min(gto[j],cgt[cur^1][i][j]);
			}
		}
		for(int i=0;i<19;i++){
			if((a[po]>>i)&1){
				for(int j=0;j<19;j++){
					cgt[cur][i][j] = min(cgt[cur][i][j],gto[j]);
					if((a[po]>>j)&1)cgt[cur][i][j]=po;
				}
			}
		}
		int x = po;
		for(auto ct:que[x]){
			int y = ct.first,e = ct.second;
			for(int i=0;i<19;i++){
				for(int j=0;j<19;j++){
					if(((a[x]>>i)&1) && (a[y]>>j)&1){
						if(cgt[cur][i][j]<=y){
							ans[e] = 1;
						}
					}
				}
			}
		}
	}
	for(int e=0;e<q;e++){
		if(ans[e]){
			cout<<"Shi\n";
		}else{
			cout<<"Fou\n";
		}
	}
	return 0;
}