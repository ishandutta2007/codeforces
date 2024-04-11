#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005,I100=po(100,P-2);
int n,x[N],v[N],p[N];
struct mat{
	int x[2][2];
	void clear(){memset(x,0,sizeof(x));}
}t[N*4],ma[N];
struct ff{
	int fz,fm,id,*num;
	bool operator<(const ff&k)const{
		return 1LL*fz*k.fm<1LL*k.fz*fm;
	}
}A[N*2];
int len;
mat mu(const mat&k1,const mat&k2){
	mat k3;
	k3.clear();
	rep(i,0,1)rep(j,0,1)rep(k,0,1)k3.x[i][k]=ad(k3.x[i][k],mu(k1.x[i][j],k2.x[j][k]));
	return k3;
}
void upd(int k1){
	t[k1]=mu(t[k1*2],t[k1*2+1]);
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1]=ma[k2];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4){
	if(k2==k3){
		t[k1]=ma[k2];
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4);else mdf(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
int inv[2000005];
int main(){
	inv[0]=inv[1]=1;
	rep(i,2,2000004)inv[i]=mu(P-P/i,inv[P%i]);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&x[i],&v[i],&p[i]),p[i]=mu(p[i],I100);
	if(n==1){
		puts("0");
		return 0;
	}
	rep(i,1,n-1){
		rep(j,0,1)rep(k,0,1){
			ma[i].x[j][k]=k?p[i+1]:su(1,p[i+1]);
		}
		A[++len]=(ff){x[i+1]-x[i],v[i]+v[i+1],i,&ma[i].x[1][0]};
		if(v[i]<v[i+1]){
			A[++len]=(ff){x[i+1]-x[i],v[i+1]-v[i],i,&ma[i].x[0][0]};
		}
		if(v[i]>v[i+1]){
			A[++len]=(ff){x[i+1]-x[i],v[i]-v[i+1],i,&ma[i].x[1][1]};
		}
	}
	bud(1,1,n-1);
	sort(A+1,A+1+len);
	auto calc=[&]{
		return ad(mu(p[1],ad(t[1].x[1][0],t[1].x[1][1])),mu(su(1,p[1]),ad(t[1].x[0][0],t[1].x[0][1])));
	};
	int ans=0;
	int lst=calc();
	rep(i,1,len){
		*A[i].num=0;
		mdf(1,1,n-1,A[i].id);
		int cur=calc();
		ans=ad(ans,mu(su(lst,cur),mu(A[i].fz,inv[A[i].fm])));
		lst=cur;
	}
	printf("%d\n",ans);
	return 0;
}