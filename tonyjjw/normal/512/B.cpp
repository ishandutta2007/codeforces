//*
#include<stdio.h>
#include<map>
#pragma warning(disable:4996)
#define MN 300

using namespace std;

int N;
int A[MN],C[MN];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

map<int,int> M;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j;
	for(i=0;i<N;i++){
		int n,newn=1;
		scanf("%d",&n);
		for(j=2;j*j<=n;j++){
			if(n%j==0)newn*=j;
			while(n%j==0){
				n/=j;
			}
		}
		newn*=n;
		A[i]=newn;
	}
	for(i=0;i<N;i++)scanf("%d",&C[i]);
	map<int,int>::iterator it;
	int a,b,g;
	int ans=1e9;
	for(i=0;i<N;i++){
		M.clear();
		M[A[i]]=C[i];
		for(j=i+1;j<N;j++){
			for(it=M.begin();it!=M.end();it++){
				a=it->first;
				b=it->second;
				g=gcd(a,A[j]);
				if(M.find(g)==M.end() || M[g]>b+C[j]){
					M[g]=b+C[j];
				}
			}
		}
		if(M.find(1)!=M.end() && ans>M[1]){
			ans=M[1];
		}
	}
	if(ans==1e9){
		puts("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
//*/