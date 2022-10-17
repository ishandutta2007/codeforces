#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],it;

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		printf("? ");
		for(j=1;j<n;j++){
			printf("%d ",1);
		}
		printf("%d",i+1);
		cout<<endl;
		scanf("%d",&k);
		if(!k)break;
		it=i;
	}
	a[n]=n-it;
	for(i=1;i<=n;i++){
		if(i==a[n])continue;
		if(i<a[n]){
			printf("? ");
			for(j=1;j<n;j++){
				printf("%d ",a[n]-i+1);
			}
			printf("%d",1);
			cout<<endl;
			
			scanf("%d",&k);
			a[k]=i;
		}
		else{
			printf("? ");
			for(j=1;j<n;j++){
				printf("%d ",1);
			}
			printf("%d",i-a[n]+1);
			cout<<endl;
			
			scanf("%d",&k);
			a[k]=i;
		}
	}
	printf("! ");
	for(i=1;i<=n;i++)printf("%d ",a[i]);
}