#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1000005,P=1e9+7;
int n;
struct po{
	LL x,y;
	po operator+(const po&k)const{return(po){x+k.x,y+k.y};}
	po operator-(const po&k)const{return(po){x-k.x,y-k.y};}
	po operator*(const LL&k)const{return(po){x*k%P,y*k%P};}
}A[N],key;
LL cross(const po&k1,const po&k2){return 1LL*k1.x*k2.y-1LL*k1.y*k2.x;}
void md(po&x){
	x.x%=P;
	x.y%=P;
}
void md(LL&x){
	x%=P;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	LL all=0,res=0,sum=0,cur=0;
	rep(i,1,n)scanf("%lld%lld",&A[i].x,&A[i].y),A[i+n]=A[i];
	rep(i,1,n)all+=cross(A[i+1],A[i]);
	int j=0;
	rep(i,1,n){
		if(j<i+1){
			j=i+2;
			sum=0;
			cur=cross(A[i+2]-A[i],A[i+1]-A[i]);
		}
		while(j<i+n-1&&cur<=all/2){
			key=key+A[j];
			md(key);
			sum+=cur;
			md(sum);
			cur+=cross(A[j+1]-A[i],A[j]-A[i]);
			++j;
		}
		res+=(j-i-2)*(all%P)%P-sum*2%P;
		cur-=cross(A[j]-A[i],A[i+1]-A[i]);
		sum-=cross(key-A[i]*(j-i-2),A[i+1]-A[i]);
		md(sum);
		key=key-A[i+2];
		md(key);
	}
	printf("%lld\n",(res%P+P)%P);
	return 0;
}