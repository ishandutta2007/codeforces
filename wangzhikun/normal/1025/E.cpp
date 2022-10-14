//  Created by  on 2018/8/19.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int m,n,px[60][2],py[60][2],mp[60][60] = {0},taken = 0;
int ops = 0,ox[11000][2],oy[11000][2];
void adop(int x,int y,int x1,int y1){
	ox[ops][0] = x;ox[ops][1] = x1;
	oy[ops][0] = y;oy[ops][1] = y1;
	ops+=1;
}
void psh(int x,int y,int dx,int dy){
	if(mp[x+dx][y+dy] != 0)psh(x+dx,y+dy,dx,dy);
	adop(x,y,x+dx,y+dy);
	swap(mp[x][y],mp[x+dx][y+dy]);
}
int getv(int x,int y){
	if(!mp[x][y])return 6666666;
	if(px[mp[x][y]][1]!=1)return px[mp[x][y]][1]*51-py[mp[x][y]][1];
	return py[mp[x][y]][1];
}
int main() {
	read(m);read(n);
	for(int i=1;i<=n;i++){
		read(px[i][0]);read(py[i][0]);
		mp[px[i][0]][py[i][0]] = i;
	}
	for(int i=1;i<=n;i++){
		read(px[i][1]);read(py[i][1]);
	}
	taken = m-n;
	for(int i=1;i<=m;i++){
		int p = 1;
		while(p<=m){
			if(mp[i][p]){
				taken+=1;
				while(p<taken){psh(i,p,0,1); p+=1;}
				while(p>taken){psh(i,p,0,-1);p-=1;}
			}
			p+=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]){
				for(int k=i;k>1;k--)adop(k, j, k-1, j);
				swap(mp[1][j],mp[i][j]);
			}
		}
	}
	for(int i=m-n+1;i<=m;i++){
		int minv = getv(1,i),minp = i;
		for(int j=i+1;j<=m;j++){
			if(getv(1,j)<minv){
				minv = getv(1, j);
				minp = j;
			}
		}
		if(minp!=i){
			psh(1,minp,1,0);
			psh(1,i,0,1);
			for(int j=minp;j>i;j--){
				psh(2,j,0,-1);
			}
			psh(2,i,-1,0);
		}
	}
	for(int i=m-n+1;i<=m;i++){
		if(px[mp[1][i]][1] == 1)continue;
		int tx = px[mp[1][m]][1],ty = py[mp[1][m]][1];
		for(int i=1;i<tx;i++)psh(i,m,1,0);
		for(int i=m;i>ty;i--)psh(tx,i,0,-1);
		if(i!=m)psh(1,i,0,1);
	}
	int p = 1;
	while(p<=m){
		if(mp[1][p]){
			while(p<py[mp[1][p]][1]){psh(1,p,0,1); p+=1;}
			while(p>py[mp[1][p]][1]){psh(1,p,0,-1);p-=1;}
		}
		p+=1;
	}
	cout<<ops<<endl;
	for(int i=0;i<ops;i++){
		cout<<ox[i][0]<<' '<<oy[i][0]<<' '<<ox[i][1]<<' '<<oy[i][1]<<endl;
	}
	return 0;
}