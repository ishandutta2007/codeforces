//*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int n,m;

bool chk(int k){
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=k;i++){
		if(i%6==0){
			c1++;
		}
		else if(i%2==0){
			c2++;
		}
		else if(i%3==0){
			c3++;
		}
	}
	int r1=max(0,n-c2);
	int r2=max(0,m-c3);
	return r1+r2<=c1;
}

int main(){
	scanf("%d%d",&n,&m);
	int l=0,m,r=5000000,ans;
	while(l<=r){
		m=(l+r)>>1;
		if(chk(m)){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	printf("%d\n",ans);
	return 0;
}

//*/