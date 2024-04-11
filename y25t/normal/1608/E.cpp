#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define fr first
#define sc second
#define inf 0x3f3f3f3f 
#define N 100005

int n;

std::vector<pii> B[3],A[8][3];

inline bool chk(int x){
	int p[3]={0,1,2};
	do{
		for(int o=0;o<4;o++){
			int u=A[o<<1][p[0]][x-1].fr+1;
			int y=x,v=inf;
			for(auto [i,j]:A[o<<1][p[1]])
				if(i>=u&&!--y){
					v=i+1;
					break;
				}
			y=x;
			for(auto [i,j]:A[o<<1][p[2]])
				if(i>=v&&!--y)
					return 1;
			y=x,v=inf;
			for(auto [i,j]:A[o<<1|1][p[1]])
				if(i>=u&&!--y){
					v=j+1;
					break;
				}
			y=x;
			for(auto [i,j]:A[o<<1|1][p[2]])
				if(i>=u&&j>=v&&!--y)
					return 1;
		}
	}while(std::next_permutation(p,p+3));
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		B[c-1].emplace_back(x,y);
	}
	for(int oo=0;oo<2;oo++){
		for(int o=0;o<2;o++){
			for(int i=0;i<3;i++){
				int x=(oo<<2)|(o<<1);
				A[x][i]=B[i],std::sort(A[x][i].begin(),A[x][i].end());
				A[x|1][i]=B[i],std::sort(A[x|1][i].begin(),A[x|1][i].end(),[](pii u,pii v){
					return u.sc==v.sc?u.fr<v.fr:u.sc<v.sc;
				});
			}
			for(int i=0;i<3;i++)
				for(auto &[u,v]:B[i])
					u*=-1;
		}
		for(int i=0;i<3;i++)
			for(auto &[u,v]:B[i])
				std::swap(u,v);
	}
	int L=1,R=n/3,res=L;
	while(L<=R){
		int mid=(L+R)>>1;
		if(chk(mid))
			res=mid,L=mid+1;
		else
			R=mid-1;
	}
	printf("%d\n",3*res);
}