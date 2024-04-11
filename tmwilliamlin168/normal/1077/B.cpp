#include<cstdio>
int n,a,b,c,d;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		if(a==1&&b==0&&c==1)c=0,d++;
		a=b;b=c;
	}
	printf("%d\n",d);
}