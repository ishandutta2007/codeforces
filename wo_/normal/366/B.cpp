#include<cstdio>
#include<algorithm>

using namespace std;

int a[100100];

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	int po=1<<29,id=-1;
	for(int i=0;i<K;i++){
		int sum=0;
		for(int j=i;j<N;j+=K){
			sum+=a[j];
		}
		if(sum<po){
			po=sum;
			id=i;
		}
	}
	printf("%d\n",id+1);
	return 0;
}