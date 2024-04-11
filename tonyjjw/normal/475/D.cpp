//*

#include<stdio.h>
#include<algorithm>
#include<map>
#pragma warning(disable:4996)
#define MN 100000
#define TN 131072

using namespace std;

int N,Q;
int A[MN],T[2*TN],q[3*MN];

map<int,long long> ans;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int get(int l,int r){
	int v=0;
	for(l+=TN,r+=TN;l<=r;l>>=1,r>>=1){
		if(l&1)v=gcd(T[l],v),++l;
		if(!(r&1))v=gcd(T[r],v),--r;
	}
	return v;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,p,l,m,r,v,n;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
		T[TN+i]=A[i];
	}
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		scanf("%d",&q[i]);
		ans[q[i]]=0;
	}
	for(i=TN-1;i>=0;i--)T[i]=gcd(T[2*i],T[2*i+1]);
	for(i=0;i<N;i++){
		p=i;
		v=A[i];
		while(p<N){
			if(get(i,N-1)==v){
				ans[v]+=(long long)N-p;
				break;
			}
			for(n=TN+p;T[n]%v==0;n>>=1){
				if(n&1)n++;
			}
			while(n<TN){
				if(T[2*n]%v==0)n=2*n+1;
				else	n=2*n;
			}
			n-=TN;
			if(ans.find(v)!=ans.end()){
				ans[v]+=(long long)n-p;
			}
			p=n;
			v=get(i,p);
		}
	}
	for(i=0;i<Q;i++){
		printf("%lld\n",ans[q[i]]);
	}
	return 0;
}

//*/