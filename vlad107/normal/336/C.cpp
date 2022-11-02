#include <stdio.h>
using namespace std;
int n;
int a[500500],P[35];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	P[0]=0;
	for (int i=0;i<31;i++)P[i+1]=2*P[i]+1;
	for (int i=30;i>=0;i--){
		int x=-1,t=0;
		for (int j=0;j<n;j++){
			if ((a[j]&(P[i]+1))==0)continue;
			if (x<0)x=a[j];else x&=a[j];
			++t;
		}
		if (x<0)continue;
		if ((i!=0)&&((x&P[i])!=0))continue;
		printf("%d\n",t); 
		for (int j=0;j<n;j++){
			if ((a[j]&(P[i]+1))==0)continue;
			printf("%d ",a[j]);
		}
		return 0;
	}
}