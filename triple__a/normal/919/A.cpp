#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;

int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int ans_a=10000,ans_b=1;
	for (int i=1;i<=n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		if (ans_a*v>ans_b*u){
			ans_a=u,ans_b=v;
		}
	}
	printf("%.8lf",1.0*ans_a*m/ans_b);
	return 0;
}