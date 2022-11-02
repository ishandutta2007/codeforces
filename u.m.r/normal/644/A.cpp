#include<cstdio>
int n, a, b, A[2],i,j;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	A[0]--;
	if (n <= a * b)
		for(i=1;i<=a;i++)for(j=1;j<=b;j++)
			printf("%d%c", ((A[i&1^j&1]<=n-2)?A[i&1^j&1]+=2:0)," \n"[j==b]);
	else
		puts("-1");
	return 0;
}