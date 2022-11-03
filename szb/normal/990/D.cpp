#include<bits/stdc++.h>
#define pc putchar
int n,a,b,x[1005][1005];
#define Rep(i,a,b) for(int i=(a);i<=(b);++i)
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(n==1){
		puts("YES");
		puts("0");
		return 0;
	} else
	if(n==2 && a==1 && b==1){
		puts("NO");
		return 0;
	} else
	if(n==3 && a==1 && b==1){
		puts("NO");
		return 0;
	} else
	if(a==1 && b==1){
		Rep(i,1,n-1) x[i][i+1] = x[i+1][i] = true;
	} else
	if(a>1 && b>1){
		puts("NO");
		return 0;
	} else
	if(b == 1){
		memset(x,0,sizeof(x));
		Rep(i,1,n-a+1){
			Rep(j,1,n-a+1){
				x[i][j] = 1;
			}
		}
	} else
	if(a==1){
		Rep(i,1,n-b+1){
			Rep(j,1,n-b+1){
				x[i][j] = 1;
			}
		}
		Rep(i,1,n){
			Rep(j,1,n){
				x[i][j] ^= i!=j;
			}
		}
	}
	puts("YES");
	Rep(i,1,n){
		Rep(j,1,n){
			if(i==j) pc('0'); else pc(x[i][j]+'0');
		}
			puts("");
	}
}
/*
n == 3

*/