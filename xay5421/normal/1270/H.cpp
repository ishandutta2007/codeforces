#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int n,q,a[N],tag[N<<2],mn[N<<2],val[N<<2];
void pst(int k1,int k2){mn[k1]+=k2,tag[k1]+=k2;} 
void psd(int k1){if(tag[k1])pst(k1*2,tag[k1]),pst(k1*2+1,tag[k1]),tag[k1]=0;}
void upd(int k1){
	val[k1]=0;
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	if(mn[k1*2]==mn[k1])val[k1]+=val[k1*2];
	if(mn[k1*2+1]==mn[k1])val[k1]+=val[k1*2+1];
//	printf(">>> upd:%d %d %d\n",k1,mn[k1],val[k1]);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
//	if(k1==1)printf(">>> add:%d %d %d %d %d %d\n",k1,k2,k3,k4,k5,k6);
	if(k5<k2||k3<k4)return;
	if(k4<=k2&&k3<=k5){pst(k1,k6);return;}
	psd(k1);int mid=k2+k3>>1;
	add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void add(int k1,int k2,int k3){
	if(k1>k2)swap(k1,k2);
	++k1;
	if(k1<=k2){
		add(1,1,1000001,k1,k2,k3);
	}
}
//void deb(int k1){
//	printf(">>> debug(%d) tag:%d mn:%d val:%d\n",k1,tag[k1],mn[k1],val[k1]);
//}
void mdf(int k1,int k2,int k3,int k4,int k5){
//	if(k1==1)printf(">>> mdf:%d %d %d %d %d\n",k1,k2,k3,k4,k5);
	if(k2==k3){val[k1]=k5;return;}
	psd(k1);int mid=k2+k3>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4,k5);else mdf(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
//	deb(k1);
}
int main(){
	rd(n),rd(q);
	for(int i=1;i<=n;++i)rd(a[i]);
	a[0]=1000001;
	for(int i=0;i<=n;++i)add(a[i],a[i+1],1);
	for(int i=1;i<=n;++i)mdf(1,1,1000001,a[i],1);
//	deb(1);
	for(int i=1;i<=q;++i){
		int k1,k2;rd(k1),rd(k2);
		add(a[k1-1],a[k1],-1);
		add(a[k1],a[k1+1],-1);
		mdf(1,1,1000001,a[k1],0);
		a[k1]=k2;
		add(a[k1-1],a[k1],1);
		add(a[k1],a[k1+1],1);
		mdf(1,1,1000001,a[k1],1);
//		deb(1);
		pt(val[1],'\n');
	}
	return 0;
}