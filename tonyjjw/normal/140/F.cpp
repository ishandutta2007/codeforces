#include<stdio.h>
#include<algorithm>
#define MN 200000
#define MK 150
//#pragma warning(disable:4996)

int N,K,S,ans;

struct POINT{
	double x,y;
	bool operator <(POINT A)const{
		if(x==A.x)return y<A.y;
		return x<A.x;
	}
	bool operator ==(POINT A)const{
		return x==A.x && y==A.y;
	}
	POINT operator +(POINT A)const{
		POINT V;
		V.x=(x+A.x);
		V.y=(y+A.y);
		return V;
	}
	POINT operator *(double a)const{
		POINT V;
		V.x=a*x;
		V.y=a*y;
		return V;
	}
}A[MN],C[MK],P[MK];

int main(){
	int i,j,k,cnt;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	if(N<=K){
		puts("-1");
		return 0;
	}
	for(i=0;i<N;i++){
		scanf("%lf%lf",&A[i].x,&A[i].y);
	}
	std::sort(A,A+N);
	for(i=0;i<K+1 && i<N;i++){
		for(j=0;j<K+1 && j<N;j++){
			C[S]=(A[i]+A[N-1-j])*0.5;
			S++;
		}
	}
	for(i=0;i<S;i++){
		cnt=0;
		for(j=0,k=N-1;j<N;j++){
			POINT V=C[i]*2+A[j]*(-1);
			while(k>0 && V<A[k])k--;
			if(!(V==A[k])){
				cnt++;
			}
		}
		if(cnt<=K){
			P[ans++]=C[i];
		}
	}
	std::sort(P,P+ans);
	ans=std::unique(P,P+ans)-P;
	printf("%d\n",ans);
	for(i=0;i<ans;i++){
		printf("%.1lf %.1lf\n",P[i].x,P[i].y);
	}
	return 0;
}