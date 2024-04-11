#include<cstdio>
#include<algorithm>

using namespace std;

typedef double Real;

typedef pair<long long,long long> P;

int N;
P ps[100100];
int M;

Real pw[500];

inline Real getPw(int x){
	if(x<500) return pw[x];
	return 0;
}

inline P get(int id){
	while(id<0) id+=N;
	while(id>=N) id-=N;
	return ps[id];
}

inline long long crP(long long a,long long b,long long c,long long d){
	return a*d-b*c;
}

long long gcd(long long a,long long b){
	if(a<0) a*=-1;
	if(b<0) b*=-1;
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

Real calc1(){
	Real res=0;
	for(int i=0;i<N;i++){
		for(int d=0;d<M;d++){
			P p1=get(i);
			P p2=get(i+d+1);
			long long a=crP(p1.first,p1.second,p2.first,p2.second);
			Real num=getPw(d+2)-getPw(N);
			Real den=1.0-(N*getPw(N))-(1.0*getPw(N))-((Real)N*(N-1)*getPw(N+1));
			Real tmp=(Real)a/2/den*num;
//			printf("%d %d %f %f %f %f\n",i,i+d,(Real)a,num,den,tmp);
			res+=tmp;
		}
	}
//	printf("\n");
	return res;
}

Real calc2(){
	Real res=0;
	for(int i=0;i<N;i++){
		for(int d=0;d<M;d++){
			P p1=get(i);
			P p2=get(i+d+1);
			long long x=gcd(p1.first-p2.first,p1.second-p2.second);
			Real num=getPw(d+2)-getPw(N);
			Real den=1.0-(N*getPw(N))-(1.0*getPw(N))-((Real)N*(N-1)*getPw(N+1));
			Real tmp=(Real)x/den*num;
//			printf("%d %d %f %f %f %f\n",i,i+d,(Real)x,num,den,tmp);
			res+=tmp;
		}
	}
	return res;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ps[i]=P(x,y);
	}
	M=min(100,N-2);
	pw[0]=1;
	for(int i=1;i<500;i++){
		pw[i]=pw[i-1]/2;
	}
	Real area=calc1();
	Real on=calc2();
//	printf("%f %f\n",area,on);
	Real ans=area+1-on/2;
	printf("%.12f\n",ans);
	return 0;
}