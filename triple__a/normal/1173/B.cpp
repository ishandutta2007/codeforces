#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",1+n/2);
	int j=1,k=1;
	for (int i=1;i<=n;++i){
		printf("%d %d\n",j,k);
		if (i%2==0){
			j++;
		}
		else{
			k++;
		}
	}
	return 0;
}