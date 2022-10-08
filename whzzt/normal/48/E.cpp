#include<bits/stdc++.h>

using namespace std;

const int N=205,M=40005;
struct pi{
	int key,day;
	pi(int a=0,int b=0){key=a,day=b;}
	friend bool operator<(const pi&x,const pi&y){
		if(x.key!=y.key)return x.key<y.key;
		if(!x.key)return x.day<y.day;
		return x.day>y.day;
	}
	pi update(){return pi(key,day+1);}
}f[N][N],ans;

bool vis[N][N],ist[N][N];
int n,m,R,a,b,inca[N][2],incb[N][2],qx[M],qy[M],ql,qr,dist[N][N];

void bfs(){
	ql=qr=1,qx[1]=n,qy[1]=m,dist[n][m]=1;
	while(ql<=qr){
		int hd=qx[ql],tl=qy[ql];ql++;
		for(int i=1,lm=min(hd,a);i<=lm;i++){
			int nd=hd-i+inca[i][0],nt=tl+inca[i][1];
			if(nd+nt>R)continue;
			if(!dist[nd][nt]){
				++qr,qx[qr]=nd,qy[qr]=nt;
				dist[nd][nt]=dist[hd][tl]+1;
			}
		}
		for(int i=1,lm=min(tl,b);i<=lm;i++){
			int nd=hd+incb[i][0],nt=tl-i+incb[i][1];
			if(nd+nt>R)continue;
			if(!dist[nd][nt]){
				++qr,qx[qr]=nd,qy[qr]=nt;
				dist[nd][nt]=dist[hd][tl]+1;
			}
		}
	}
	if(dist[0][0]){ans=pi(2,dist[0][0]-2);return;}
}

pi dfs(int hd,int tl){
	if(hd+tl>R)return pi();
	if(ist[hd][tl])return ans=pi(1,0);
	if(vis[hd][tl])return f[hd][tl];
	if(ans.key)return pi();
	vis[hd][tl]=ist[hd][tl]=true;
	pi&ret=f[hd][tl];
	for(int i=1,lm=min(hd,a);i<=lm;i++){
		ret=max(ret,dfs(hd-i+inca[i][0],tl+inca[i][1]));
		if(ret.key)break;
	}
	for(int i=1,lm=min(tl,b);i<=lm;i++){
		ret=max(ret,dfs(hd+incb[i][0],tl-i+incb[i][1]));
		if(ret.key)break;
	}
	ret.day++;
	ist[hd][tl]=false;
	return ret;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&R,&a);
	for(int i=1;i<=a;i++)scanf("%d%d",&inca[i][0],&inca[i][1]);
	scanf("%d",&b); 
	for(int i=1;i<=b;i++)scanf("%d%d",&incb[i][0],&incb[i][1]);
	bfs();
	if(!ans.key){
		for(int i=1;i<=min(n,a);i++){
			ans=max(ans,dfs(n-i+inca[i][0],m+inca[i][1]));
			if(ans.key)break;
		}
		for(int i=1;i<=min(m,b);i++){
			ans=max(ans,dfs(n+incb[i][0],m-i+incb[i][1]));
			if(ans.key)break;
		}
	}
	ans.day++;
	switch(ans.key){
		case 2:printf("Ivan\n%d\n",ans.day);break;
		case 1:printf("Draw");break;
		case 0:printf("Zmey\n%d\n",ans.day);break;
	}
	return 0;
}