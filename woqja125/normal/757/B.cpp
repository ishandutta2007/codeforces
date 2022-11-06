#include<stdio.h>
int c[100001];
int main()
{
	int n, s;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &s);
		for(int j=1; 1ll*j*j<=s; j++){
			if(s%j == 0){
				c[j]++;
				if(s/j != j) c[s/j]++;
			}
		}
	}
	int m=1;
	for(int i=2; i<=100000; i++){
		if(m<c[i])m=c[i];
	}
	printf("%d", m);
	return 0;
}