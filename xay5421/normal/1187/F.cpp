#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005,P=1000000007;
int n,l[N],r[N],p[N],q[N],sp[N];
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
template<typename T>T min(const T&x,const T&y,const T&z){return min(x,min(y,z));}
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>T max(const T&x,const T&y,const T&z){return max(x,max(y,z));}
int fpow(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;return res;}
int get(int l1,int r1,int l2,int r2){
//	printf("%d %lld\n",max(0,min(r1,r2)-max(l1,l2)+1),1ll*(r1-l1+1)*(r2-l2+1)%P);
	return 1ll*max(0,min(r1,r2)-max(l1,l2)+1)*fpow(1ll*(r1-l1+1)*(r2-l2+1)%P,P-2)%P;
}
int get2(int l1,int r1,int l2,int r2,int l3,int r3){
	return 1ll*max(0,min(r1,r2,r3)-max(l1,l2,l3)+1)*fpow(1ll*(r1-l1+1)*(r2-l2+1)%P*(r3-l3+1)%P,P-2)%P;
}
int calc(int i){
	int res=(1ll-q[i]-q[i+1]+(i>1?get2(l[i-1],r[i-1],l[i],r[i],l[i+1],r[i+1]):0))%P;
	return (res+P)%P;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",l+i);rep(i,1,n)scanf("%d",r+i);
	rep(i,1,n)q[i]=get(l[i-1],r[i-1],l[i],r[i]),p[i]=P+1-q[i],sp[i]=(sp[i-1]+p[i])%P;
	int ans=0;
//	rep(i,1,n)printf("%d %d\n",i,calc(i));
	rep(i,1,n){
		(ans+=p[i])%=P;
//		printf("1:%d\n",ans);
		(ans+=1ll*p[i]*(sp[max(0,i-2)]+(sp[n]-sp[min(i+1,n)]+P)%P)%P)%=P;
//		printf("2:%d\n",ans);
		if(i>1)(ans+=calc(i-1))%=P;
		if(i+1<=n)(ans+=calc(i))%=P;
//		printf("3:%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}