#include"bits/stdc++.h"
using namespace std;
int n;bool fl[100005];
int main(){
	cin>>n;
	if(n==1){printf("1\n1");return 0;}
	if(n==2){printf("1\n1 1");return 0;}
	printf("2\n");
	for(int i=2;i<=n+1;i++){
		if(fl[i])printf("2 ");else printf("1 ");
		for(int j=1;i*j<=n+1;j++)fl[i*j]=true;
	}
	return 0;
}