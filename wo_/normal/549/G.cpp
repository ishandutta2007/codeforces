#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int N;
int a[200200];
int b[200200];

int c[200200];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++){
		c[i]=a[i]+i;
	}
	sort(c,c+N);
	for(int i=0;i<N;i++){
		b[i]=c[i]-i;
	}
	for(int i=0;i+1<N;i++){
		if(b[i]>b[i+1]){
			printf(":(\n");
			return 0;
		}
	}
	for(int i=0;i<N;i++){
		printf("%d%c",b[i],i==N-1?'\n':' ');
	}
	return 0;
}