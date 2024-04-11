#include<cstdio>

using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=0;
	int gone=0;
	int n=a;
	while(true){
		ans+=n;
		gone+=n;
		n=0;
		n=gone/b;
		gone=gone%b;
		if(n==0) break;
	}
	printf("%d\n",ans);
	return 0;
}