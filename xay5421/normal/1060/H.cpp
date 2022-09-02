#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int d,P,ind=2,zero,one;
int a[100005];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
void add(int k1,int k2,int k3){
	a[k3]=(a[k1]+a[k2])%P;
	printf("+ %d %d %d\n",k1,k2,k3);
	D("now a[%d]=%d\n",k3,a[k3]);
}
void powd(int k1,int k2){
	a[k2]=fpow(a[k1],d);
	printf("^ %d %d\n",k1,k2);
	D("now a[%d]=%d\n",k2,a[k2]);
}
void get0(){
	static int buf=0;
	if(!buf)buf=++ind;
	zero=++ind;
	for(int i=P-1;i;i>>=1,add(buf,buf,buf))if(i&1)add(buf,zero,zero);
}
void set0(int k1){add(zero,zero,k1);}
void set1(int k1){add(one,zero,k1);}
void mul(int k1,int k2,int k3){ // a[k3]=a[k1]*k2
	static int buf=0;
	if(!buf)buf=++ind;
	add(zero,k1,buf);
	set0(k3);
	for(int i=k2;i;i>>=1,add(buf,buf,buf))if(i&1)add(buf,k3,k3);
	assert(a[k3]==1LL*a[k1]*k2%P);
}
void sub(int k1,int k2,int k3){
	static int buf=0;
	if(!buf)buf=++ind;
	mul(k2,P-1,buf);
	assert((a[buf]+a[k2])%P==0);
	add(k1,buf,k3);
	assert(a[k3]==(a[k1]-a[k2]+P)%P);
}
void div(int k1,int k2,int k3){ // a[k3]=a[k1]/k2
	k2=fpow(k2,P-2);
	mul(k1,k2,k3);
}
int C[15][15],f[15][15],ans[15];
void fuck(){
	for(int i=0;i<15;++i){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	rep(i,0,d)rep(j,0,d)f[i][j]=1LL*C[d][i]*fpow(j,d-i)%P;
	f[2][d+1]=1;
	rep(i,0,d){
		rep(j,i,d)if(f[j][i]){
			swap(f[i],f[j]);
			break;
		}
		rep(j,0,d)if(j!=i){
			int num=1LL*f[j][i]*fpow(f[i][i],P-2)%P;
			rep(k,0,d+1)f[j][k]=(f[j][k]+P-1LL*f[i][k]*num%P)%P;
		}
	}
	rep(i,0,d){
		assert(f[i][i]);
		ans[i]=1LL*f[i][d+1]*fpow(f[i][i],P-2)%P;
	}
}
int pw2(int k1){
	static int buf1=0,buf2=0,buf3=0;
	if(!buf1)buf1=++ind,buf2=++ind,buf3=++ind;
	int res=++ind;
	set0(res);
	add(k1,zero,buf1);
	rep(i,0,d){
		if(i)add(buf1,one,buf1);
		powd(buf1,buf2);
		mul(buf2,ans[i],buf3);
		add(res,buf3,res);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fill(a,a+100005,1);
	cin>>d>>P;
	a[1]=114514%P,a[2]=1919810%P;
	D("a[1]=%d a[2]=%d\n",a[1],a[2]);
	one=++ind;
	get0();
	D("\n----- get0 ok -----\n\n");
	assert(a[zero]==0);
	assert(a[one]==1);
	mul(1,1234,++ind);
	sub(1,2,++ind);
	fuck();
	int pos=++ind;
	add(1,2,pos);
	int k1=pw2(1),k2=pw2(2),k3=pw2(pos);
	assert(a[k1]==1LL*a[1]*a[1]%P);
	int k4=++ind,k5=++ind,k6=++ind;
	add(k1,k2,k4);
	sub(k3,k4,k5);
	mul(k5,(P+1)/2,k6);
	printf("f %d\n",k6);
	assert(a[k6]==1LL*a[1]*a[2]%P);
	return 0;
}