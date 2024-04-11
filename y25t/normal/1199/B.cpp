#include<cstdio>
#define ld double

ld h,l;

int main(){
	scanf("%lf%lf",&h,&l);
	printf("%.7lf",(l*l-h*h)/2/h);
}