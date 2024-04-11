//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 5
#define ML 10000
using namespace std;
typedef tuple<int,int> SEG;

int N,L[MN];
SEG seg[MN];

int con(SEG A,SEG B){
	int l1,l2,r1,r2;
	tie(l1,r1)=A;
	tie(l2,r2)=B;
	tie(l1,r1)=mt(max(l1,l2),min(r1,r2));
	if(r1<l1)return 0;
	return r1-l1+1;
}
double prob(int i,SEG A){
	return (double)con(A,seg[i])/L[i];
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		seg[i]=mt(l,r);
		L[i]=r-l+1;
	}
	double ans=0;
	int p[MN]={0,};
	for(int j=0;j<N;j++)p[j]=j;
	for(int i=1;i<=ML;i++){
		for(int j=0;j<N;j++){
			swap(p[0],p[j]);
			double p1=prob(p[0],mt(i+1,ML));
			double p2=1;
			for(int k=1;k<N;k++){
				p2*=prob(p[k],mt(1,i));
			}
			double p3=1;
			for(int k=1;k<N;k++){
				p3*=prob(p[k],mt(1,i-1));
			}
			ans+=i*p1*(p2-p3);
			swap(p[0],p[j]);
		}
		double p1=1;
		for(int j=0;j<N;j++){
			p1*=prob(j,mt(1,i));
		}
		double p2=1;
		for(int j=0;j<N;j++){
			p2*=prob(j,mt(1,i-1));
		}
		double p3=0;
		for(int j=0;j<N;j++){
			swap(p[0],p[j]);
			double tp=prob(p[0],mt(i,i));
			for(int k=1;k<N;k++){
				tp*=prob(p[k],mt(1,i-1));
			}
			p3+=tp;
			swap(p[0],p[j]);
		}
		ans+=i*(p1-p2-p3);
	}
	printf("%.12lf",ans);
	return 0;
}
//*/