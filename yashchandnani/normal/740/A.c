#include<stdio.h>
long int f(long int a,long int b){
	if (a<=b/3) return 3*a;
	else return b;
}
long int min (long int a,long int b){
	if(a<b) return a;
	else return b;
}
int main(){
	long int n,a,b,c;
	scanf("%ld%ld%ld%ld",&n,&a,&b,&c);
	n = n%4;
	//printf("%ld\n",n );
	if (n==0) printf("0");
	if (n==3) printf("%ld\n",(min(f(c,a),(b+c))) );;
	if(n==2)  printf("%ld\n",(min(min(2*a,2*c),b)) );;
	if (n==1) printf("%ld\n",(min(f(a,c),(a+b))) );;
	return 0;

}