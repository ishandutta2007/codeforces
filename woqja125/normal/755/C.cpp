#include<stdio.h>
int p[10001], c[10001];
int getp(int x){ return (p[x]==x)?x:(p[x]=getp(p[x])); }
void uni(int a, int b){
	p[getp(a)]=getp(b);
}
int main()
{
	int n, t,a=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) p[i]=i;
	for(int i=1; i<=n; i++){
		scanf("%d", &t);
		uni(i, t);
	}
	for(int i=1; i<=n; i++)if(!c[getp(i)])a++, c[getp(i)]++;
	printf("%d", a);
	return 0;
}