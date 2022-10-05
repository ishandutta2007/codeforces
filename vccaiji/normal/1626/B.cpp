#include<bits/stdc++.h>
using namespace std;
int b[210000];
int n;
char a[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%s",a);
		n=strlen(a);
		for(int i=0;i<n;i++) b[i]=a[i]-'0';
		bool r=false;
		for(int i=n-2;i>=0;i--){
			if(b[i]+b[i+1]>=10){
				r=true;
				for(int j=0;j<i;j++) printf("%d",b[j]);
				printf("%d",b[i]+b[i+1]);
				for(int j=i+2;j<n;j++) printf("%d",b[j]);
				printf("\n");
				break;
			}
		}
		if(r) continue;
		printf("%d",b[0]+b[1]);
		for(int j=2;j<n;j++) printf("%d",b[j]);
		printf("\n");
	}
	return 0;
}