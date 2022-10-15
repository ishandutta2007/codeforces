#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100],b[100];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int A;
		cin>>A;
		a[A]=1;
	}
	for(int i=0;i<m;i++){
		int A;
		cin>>A;
		b[A]=1;
	}
	for(int i=1;i<100;i++){
		if((a[i%10]||(i>=10&&a[i/10]))&&(b[i%10]||(i>=10&&b[i/10]))){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}