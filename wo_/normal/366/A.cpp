#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<4;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int m1=min(a,b);
		int m2=min(c,d);
		if(m1+m2>N) continue;
		printf("%d %d %d\n",i+1,m1,N-m1);
		return 0;
	}
	printf("-1\n");
	return 0;
}