#include<cstdio>
#include<cstring>
#include<time.h>
#include<algorithm>

using namespace std;

struct RmQ{
	int N;
	int dat[2097152];
	void init(int N_,int *a){
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<N_;i++) dat[i+N]=a[i];
		for(int i=N_;i<N;i++) dat[i+N]=a[i];
		for(int i=N-1;i>=1;i--) dat[i]=min(dat[i*2],dat[i*2+1]);
	}
	int get(int l,int r,int k,int a,int b){
		if(r<=a||b<=l) return (1<<28);
		if(l<=a&&b<=r) return dat[k];
		return min(get(l,r,k*2,a,(a+b)/2),get(l,r,k*2+1,(a+b)/2,b));
	}
	int get(int l,int r){
		return get(l,r,1,0,N);
	}
};

RmQ rmq;

char ch[1100100];
int a[1100100];

int main(){
//	double start=clock();
	scanf("%s",ch);
	int ln=strlen(ch);
	a[0]=0;
	for(int i=1;i<=ln;i++){
		if(ch[i-1]=='(') a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	rmq.init(ln+1,a);
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		int mi=rmq.get(l,r+1);
		int rem=a[l]-mi;
		int x=a[r]-a[l]+rem;
		int ans=r-l-rem-x;
//		printf("%d %d %d %d %d\n",a[l],a[r],mi,rem,x);
		printf("%d\n",ans);
	}
//	double end=clock();
//	printf("%f\n",end-start);
	return 0;
}