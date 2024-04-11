#include"bits/stdc++.h"

using namespace std;

const int N=135;

int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r*=a;
		a*=a;t>>=1;
	}
	return r;
}

int temp[N];

int getc(int x,int y){
	if(x<y)return 0;
	register int i,j,k,res=1;
	memset(temp,0,(y+1)<<2);
	for(i=y;i;i--){
		for(j=i,k=2;k*k<=j;k++){
			while(j%k==0){
				temp[k]++;
				j/=k;
			}
		}
		if(j>1)temp[j]++;
	}
	for(i=x;i>x-y;i--){
		for(j=i,k=2;k<=y&&k<=j;k++){
			while(temp[k]&&j%k==0){
				temp[k]--,j/=k;
			}
		}
		res*=j;
	}
	return res;
}

int n,p,q,c[N],ans;

int main(){
	scanf("%d%d%d",&n,&p,&q);
	if(p>=n)p=n-1;
	register int i,j,k,w;
	for(i=0;i<=p;i++)
		c[i]=getc(n,i);
	for(i=1;i<=q;i++){
		for(j=w=0,k=1;j<=p;j++,k*=i)w+=c[j]*k;
		ans^=w*i;
	}
	printf("%u\n",ans);
	return 0;
}