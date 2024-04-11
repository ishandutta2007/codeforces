#include"algorithm"
#include"iostream"
#include"string.h"
#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"vector"
#include"bitset"
#include"queue"
#include"map"
#include"set"

using namespace std;
typedef long long LL;

const int N=1005;

struct P{
	LL x,y,z;
	P(LL _x=0,LL _y=0,LL _z=0){
		x=_x,y=_y,z=_z;
	}
	void init(){
		scanf("%lld%lld%lld",&x,&y,&z);
	}
	friend P operator-(P a,P b){
		return P(a.x-b.x,a.y-b.y,a.z-b.z);
	}
}X,Y;

LL dot(const P&a,const P&b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

P cross(const P&a,const P&b){
	return P(a.y*b.z-b.y*a.z,a.z*b.x-b.z*a.x,a.x*b.y-b.x*a.y);
}

struct L{
	P u,v,l;
	L(P _u=P(0,0),P _v=P(0,0)){
		u=_u,v=_v,l=v-u;
	}
}li[N];

bool cr(const L&a,const L&b){
	P z=cross(a.l,b.l);
	if(z.x==0&&z.y==0&&z.z==0)return false;
	return dot(z,b.v-a.v)==0;
}

int n,deg[N],k,p[N],m;
bitset<1005>link[N],ok;

int check(){
	for(int i=1;i<=m;i++)swap(p[i],p[rand()%m+1]);
	ok=0,ok=~ok;
	int ans=0;
	for(int i=1;i<=m;i++){
		if(ok[p[i]])ans++,ok&=link[p[i]];
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	srand((size_t)new char);
	for(int i=1;i<=n;i++){
		X.init(),Y.init();
		li[i]=L(X,Y);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cr(li[i],li[j])){
				link[i][j]=1,link[j][i]=1;
				deg[i]++,deg[j]++;
			}
		}
	}
	int l=1,r=n,mid=(l+r+1)>>1,lim=400,t,x;
	while(l<r){
		m=0;
		for(x=1;x<=n;x++)if(deg[x]>=mid-1)p[++m]=x;
		if(m>=mid){
			bool flag=true;
			for(t=1;t<=10000;t++){
				x=check();
				if(x>=mid){
					l=x;
					flag=false;
					break;
				}
			}
			if(flag)r=mid-1;
		}else r=mid-1;
		mid=(l+r+1)>>1;
		lim+=400;
	}
	printf("%d\n",mid);
	return 0;
}