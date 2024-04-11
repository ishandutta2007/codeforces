#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=155,INF=0X3F3F3F3F;
int n,m,dis[N];
struct data{
	int x,y,z;
	bool operator<(const data&k2)const{return z<k2.z;}
	void in(){scanf("%d%d%d",&x,&y,&z);}
}e[N];
struct mat{
	bitset<N>x[N];
	mat operator*(const mat&k2)const{
		mat k3;rep(i,1,n)k3.x[i].reset();
		rep(i,1,n)rep(j,1,n)if(x[i][j])k3.x[i]|=k2.x[j];
		return k3;
	}
}A,C;
bitset<N>operator*(const bitset<N>&k1,const mat&k2){
	bitset<N>k3(0);
	rep(i,1,n)if(k1[i])k3|=k2.x[i];
	return k3;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)e[i].in();sort(e+1,e+1+m);
	bitset<N>B;B.set(1);
	int ans=INF;
	rep(i,1,m){
		int num=e[i].z-e[i-1].z;
		A=C;
		while(num){
			if(num&1)B=B*A;
			A=A*A,num>>=1;
		}
		C.x[e[i].x].set(e[i].y);
		queue<int>q;
		rep(i,1,n)if(B[i])q.push(i),dis[i]=0;else dis[i]=INF;
		while(!q.empty()){
			int k1=q.front();q.pop();
			rep(k2,1,n)if(dis[k2]==INF&&C.x[k1][k2])q.push(k2),dis[k2]=dis[k1]+1;
		}
		ans=min(ans,e[i].z+dis[n]);
	}
	if(ans==INF)puts("Impossible");else printf("%d\n",ans);
	return 0;
}