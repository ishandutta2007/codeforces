// author: xay5421
// created: Wed Jan 13 17:57:27 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,m,Q;
struct mat{
	int a[2][2];
	void clear(){memset(a,0,sizeof(a));}
	mat operator*(const mat&b)const{
		mat c;
		rep(i,0,1)rep(j,0,1)c.a[i][j]=min(a[i][0]+b.a[0][j],a[i][1]+b.a[1][j]);
		return c;
	}
};
struct solver{
	int n,m,len[N*4];
	char up[N],dw[N];
	mat t[N*4][4];
	int s[N*4][2],rev[N*4];
	mat get(int t){
		return (mat){{{t,n+2-t},{n+t,2-t}}};
	}
	void init(int _n,int _m){
		n=_n,m=_m;
		scanf("%s%s",up+1,dw+1);
		rep(i,1,m)up[i]=up[i]=='B';
		rep(i,1,m)dw[i]=dw[i]=='B';
		bud(1,1,m);
	}
	void upd(int k1){
		rep(i,0,1)s[k1][i]=s[k1*2][i]+s[k1*2+1][i];
		rep(i,0,3)t[k1][i]=t[k1*2][i]*t[k1*2+1][i];
	}
	void pst(int k1,int k2){
		if(k2&1){
			s[k1][1]=len[k1]-s[k1][1];
			swap(t[k1][0],t[k1][1]);
			swap(t[k1][2],t[k1][3]);
		}
		if(k2>>1&1){
			s[k1][0]=len[k1]-s[k1][0];
			swap(t[k1][0],t[k1][2]);
			swap(t[k1][1],t[k1][3]);
		}
		rev[k1]^=k2;
	}
	void psd(int k1){
		if(rev[k1]){
			pst(k1*2,rev[k1]);
			pst(k1*2+1,rev[k1]);
			rev[k1]=0;
		}
	}
	void bud(int k1,int k2,int k3){
		len[k1]=k3-k2+1;
		if(k2==k3){
			s[k1][0]=up[k2];
			s[k1][1]=dw[k2];
			t[k1][0]=get(up[k2]+dw[k2]);
			t[k1][1]=get(up[k2]+1-dw[k2]);
			t[k1][2]=get(1-up[k2]+dw[k2]);
			t[k1][3]=get(2-up[k2]-dw[k2]);
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
	int ask(int x,int y){
		int res=INF;
		rep(i,0,1)rep(j,0,1){
			res=min(res,(i==0?x:n-x)+(j==0?y:n-y)+t[1][0].a[i][j]);
		}
		//D("res=%d\n",res);
		return res;
	}
}t[2];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	t[1].init(m,n);
	t[0].init(n,m);
	rep(i,0,Q){
		if(i){
			char c;
			int L,R;
			cin>>c;
			scanf("%d%d",&L,&R);
			if(c=='L'){
				t[1].mdf(1,1,n,L,R,2);
			}else if(c=='R'){
				t[1].mdf(1,1,n,L,R,1);
			}else if(c=='U'){
				t[0].mdf(1,1,m,L,R,2);
			}else if(c=='D'){
				t[0].mdf(1,1,m,L,R,1);
			}
		}
		printf("%d\n",min(t[0].ask(t[1].s[1][0],t[1].s[1][1]),t[1].ask(t[0].s[1][0],t[0].s[1][1])));
	}
	return 0;
}