#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int u,v,mo,q[505];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
map<int,int> mp1,v1;
map<int,int> mp2,v2;
int main(){
	scanf("%d%d%d",&u,&v,&mo);
	mp1[u]=mp2[v]=-1;
	For(i,1,10000){
		int x=u;
		For(j,1,100){
			int tp=rand()%3+1,y=0;
			if (tp==1) y=(x+1)%mo;
			if (tp==2) y=(x+mo-1)%mo;
			if (tp==3) y=power(x,mo-2)%mo;
			if (!mp1.count(y)) mp1[y]=x,v1[y]=tp;
			x=y;
		}
	}
	For(i,1,10000){
		int x=v;
		For(j,1,100){
			int tp=rand()%3+1,y=0;
			if (tp==1) y=(x+mo-1)%mo;
			if (tp==2) y=(x+1)%mo;
			if (tp==3) y=power(x,mo-2)%mo;
			//cout<<y<<endl;
			if (!mp2.count(y)) mp2[y]=x,v2[y]=tp;
			if (mp1.count(y)){
				int tp=0;
				for (int p=y;v1[p];p=mp1[p])
					q[++tp]=v1[p];
				reverse(q+1,q+tp+1);
				for (int p=y;v2[p];p=mp2[p])
					q[++tp]=v2[p];
				printf("%d ",tp);
				For(i,1,tp) printf("%d ",q[i]);
				exit(0);
			}
			x=y;
		}
	}
}