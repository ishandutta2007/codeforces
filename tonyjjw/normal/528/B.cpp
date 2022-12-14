//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
#define TN 262144
using namespace std;

int N;
int x[MN],w[MN],tx[MN],tw[MN];
int ord[2*MN];
int T[2*TN],D[MN];

int value(int n){
	if(n>=N){
		return x[n-N]+w[n-N];
	}
	return x[n]-w[n];
}

bool cmp(int a,int b){
	int v1=value(a),v2=value(b);
	if(v1==v2){
		return a>b;
	}
	return v1<v2;
}

int p[MN];
bool cmp2(int a,int b){
	return x[a]<x[b];
}

int get(int l,int r){
	int v=0;
	l+=TN,r+=TN;
	while(l<=r){
		if(l&1){
			if(v<T[l])v=T[l];
			l++;
		}
		if(!(r&1)){
			if(v<T[r])v=T[r];
			r--;
		}
		l>>=1,r>>=1;
	}
	return v;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&x[i],&w[i]);
		p[i]=i;
	}
	sort(p,p+N,cmp2);
	for(int i=0;i<N;i++)tx[i]=x[p[i]],tw[i]=w[p[i]];
	for(int i=0;i<N;i++)x[i]=tx[i],w[i]=tw[i];

	for(int i=0;i<2*N;i++)ord[i]=i;
	sort(ord,ord+2*N,cmp);
	for(int i=0;i<2*N;i++){
		if(ord[i]<N){
			int n=ord[i];
			D[n]=get(0,n-1)+1;
		}
		else{
			int n=ord[i]-N+TN;
			while(n){
				if(T[n]<D[ord[i]-N])T[n]=D[ord[i]-N];
				n>>=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;i++){
		if(ans<D[i])ans=D[i];
	}
	printf("%d",ans);
	return 0;
}
//*/