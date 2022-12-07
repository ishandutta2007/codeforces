#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define maxn 200005
using namespace std;
int line[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&line[i]);
	if(n&1){
		for(int i=1;i<=n;i++){
			if(i&1)
				printf("%d ",line[n-i+1]);
			else
				printf("%d ",line[i]);
		}
	}
	else{
		for(int i=1;i<=n/2;i++){
			if(i&1)
				printf("%d ",line[n-i+1]);
			else
				printf("%d ",line[i]);
		}
		for(int i=n/2+1;i<=n;i++){
			if(i&1)
				printf("%d ",line[i]);
			else
				printf("%d ",line[n-i+1]);
		}
	}
	return 0;
}