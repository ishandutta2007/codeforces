#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,Q;
int t[N],dir[N],x[N],y[N],len[N],ans[N],top,st[N*2][3];
namespace BIT{
	static const int N=10005;
	int t[N][N];
	void upd(int k1,int k2,int k3){
		++top;
		st[top][0]=k1,st[top][1]=k2,st[top][2]=k3;
		for(int i=k1;i<N;i+=i&-i)for(int j=k2;j<N;j+=j&-j)t[i][j]+=k3;
	}
	int qry(int k1,int k2){
		int k3=0;
		for(int i=k1;i;i&=i-1)for(int j=k2;j;j&=j-1)k3+=t[i][j];
		return k3;
	}
	void clear(){
		while(top){
			upd(st[top][0],st[top][1],-st[top][2]);
			top-=2;
		}
	}
}
using BIT::upd;
using BIT::qry;
using BIT::clear;
int main(){
	scanf("%d%d",&n,&Q);
	rep(i,1,Q){
		scanf("%d",&t[i]);
		if(t[i]==1)scanf("%d%d%d%d",dir+i,x+i,y+i,len+i);
		else scanf("%d%d",x+i,y+i);
	}
	rep(i,1,Q){
		if(t[i]==1){
			if(dir[i]==1){
				upd(x[i],y[i],1);
			}else if(dir[i]==2){
				upd(x[i],y[i]+1,-1);
			}else if(dir[i]==3){
				upd(x[i]+1,y[i],-1);
			}else{
				upd(x[i]+1,y[i]+1,1);
			}
		}else{
			ans[i]+=qry(x[i],y[i]);
		}
	}
	clear();
	rep(i,1,Q){
		if(t[i]==1){
			if(dir[i]==1){
				upd(x[i]+y[i]+len[i]+1,y[i],-1);
			}else if(dir[i]==4){
				upd(x[i]+y[i]-len[i],y[i]+1,-1);
			}
		}else{
			ans[i]+=qry(x[i]+y[i],y[i]);
		}
	}
	clear();
	rep(i,1,Q){
		if(t[i]==1){
			if(dir[i]==1){
				upd(n-x[i]+1+1,x[i]+y[i]+len[i]+1,1);
			}else if(dir[i]==4){
				upd(n-x[i]+1,x[i]+y[i]-len[i],1);
			}
		}else{
			ans[i]+=qry(n-x[i]+1,x[i]+y[i]);
		}
	}
	clear();
	rep(i,1,Q){
		if(t[i]==1){
			if(dir[i]==2){
				upd(x[i]-y[i]+1+n+1+len[i],y[i]+1,1);
			}else if(dir[i]==3){
				upd(x[i]-y[i]+1+n-len[i],y[i],1);
			}
		}else{
			ans[i]+=qry(x[i]-y[i]+1+n,y[i]);
		}
	}
	clear();
	rep(i,1,Q){
		if(t[i]==1){
			if(dir[i]==2){
				upd(x[i],y[i]-x[i]+1+n-len[i],1);
			}else if(dir[i]==3){
				upd(x[i]+1,y[i]-x[i]+1+n+len[i]+1,1);
			}
		}else{
			ans[i]+=qry(x[i],y[i]-x[i]+1+n);
		}
	}
	rep(i,1,Q)if(t[i]==2)printf("%d\n",ans[i]);
	return 0;
}