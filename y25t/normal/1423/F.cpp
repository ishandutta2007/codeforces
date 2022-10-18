#include<cstdio>
#include<algorithm>

int n,m;

int s,t;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		s+=b;
		if(s>n){
			puts("-1");
			exit(0);
		}
		t=(t+1ll*a*b%n)%n;
	}
	if(s==n&&t!=1ll*n*(n+1)/2%n)
		puts("-1");
	else
		puts("1");
}