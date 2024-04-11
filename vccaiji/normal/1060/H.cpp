#include<bits/stdc++.h>
using namespace std;
int tot=3,d,p;
void pro0(){
	int n=p-1;
	for(;n;n>>=1){
		if(n&1)printf("+ 4999 5000 5000\n");
		printf("+ 4999 4999 4999\n");
	} 
}
int mul(int n,int i){
	int j=++tot;
	printf("+ 5000 5000 %d\n",j);
	for(;n;n>>=1){
		if(n&1)printf("+ %d %d %d\n",i,j,j);
		printf("+ %d %d %d\n",i,i,i);
	}
	return j;
}
inline int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1) ans=((long long)ans*a)%p;
		a=((long long)a*a)%p;
	}
	return ans;
}
inline int inverse(int a){
	return qow(a,p-2);
}
int o[15]={};
int oo[15]={};
int u[15]={};
int uu[15]={};
int C[15][15];
void sqinit(){
	C[0][0]=1;
	for(int i=1;i<=d;i++){
		C[i][0]=1;
		C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p; 
	}
	u[d]=1;
	for(int i=d;i>=3;i--){
		for(int j=1;j<=i;j++){
			for(int k=0;k<j;k++) uu[k]=(uu[k]+(long long)C[j][k]*u[j])%p; 
		}
		for(int j=0;j<=i;j++){
			u[j]=uu[j];
			uu[j]=0;
		}
	}
	int t=(2ll*u[2]*u[0]+1ll*(p-u[1])*(u[1]+u[2]))%p;
	t=((long long)t*inverse((2*u[2])%p))%p;
	o[2]=t;
	o[0]=t;
	o[1]=((long long)(p-2)*t)%p;
	o[1]=(o[1]+u[1])%p;
	o[0]=(o[0]+p-u[1])%p;
	for(int i=0;i<=2;i++) o[i]=((long long)o[i]*inverse(p-(2*u[2])%p))%p;
	o[0]=(o[0]+1)%p;
	for(int i=0;i<=2;i++) o[i]=((long long)o[i]*inverse(u[2]))%p;
	for(int i=d;i>=3;i--){
 		for(int j=0;j<d;j++) oo[j+1]=o[j];
 		for(int j=0;j<d;j++) oo[j]=(oo[j]+p-o[j])%p;
		for(int j=0;j<=d;j++){
			o[j]=oo[j];
			oo[j]=0;
		}
	}
}
int sq(int i){
	int jj[15];
	for(int j=0;j<=d;j++) jj[j]=tot+j+1;
	printf("+ 5000 5000 %d\n",tot+1);
	for(int j=3;j<=d+1;j++) printf("+ %d %d %d\n",tot+j-1,tot+j,tot+j);
    tot+=d+1;
	for(int j=0;j<=d;j++) printf("+ %d %d %d\n",jj[j],i,jj[j]);
	for(int j=0;j<=d;j++) printf("^ %d %d\n",jj[j],jj[j]);
	for(int j=0;j<=d;j++) jj[j]=mul(o[j],jj[j]);
	for(int j=1;j<=d;j++) printf("+ %d %d %d\n",jj[0],jj[j],jj[0]);
	return jj[0];
}
int main(){
	scanf("%d%d",&d,&p);
	pro0();
	sqinit();
	printf("+ 1 2 3\n");
	int i1=sq(1);
	int i2=sq(2);
	int i3=sq(3);
	i1=mul((p-1)/2,i1);
	i2=mul((p-1)/2,i2);
	i3=mul((p+1)/2,i3);
	printf("+ %d %d %d\n",i1,i2,i1);
	printf("+ %d %d %d\n",i1,i3,i1);
	printf("f %d\n",i1);
	return 0;
}