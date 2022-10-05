#include<bits/stdc++.h>
using namespace std;
bool ap[1100000]={};
int t[2100000];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		ap[a]=true;
	}
	int u=0;
	for(int i=1;i<=2050000;i++){
		if((i<=1000000)&&ap[i]) u=i;
		t[i]=u; 
	}
	int maxx=0;
	for(int i=1;i<=1000000;i++){
		if(ap[i]){
			for(int j=2*i-1;j<=2050000;j+=i){
				if(t[j]>=j-(i-1)) maxx=max(maxx,t[j]-(j-(i-1)));
			}
		}
	}
	printf("%d",maxx);
	return 0;
}