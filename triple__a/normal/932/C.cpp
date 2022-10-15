#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
 
int n,A,B,u=0,v=0;
int main(){
	cin>>n>>A>>B;
	for (int k=0;k<=n;++k){
		if (n<k*A) break;
		if ((n-k*A)%B) continue;
		u=k; v=(n-k*A)/B;
		break;
	}
	if (u==0&&v==0){
		cout<<"-1";
	}
	else{
		for (int i=1;i<=u;++i){
			for (int j=1;j<=A;++j){
				cout<<(i-1)*A+j%A+1<<" ";
			}
		}
		for (int i=1;i<=v;++i){
			for (int j=1;j<=B;++j){
				cout<<u*A+(i-1)*B+j%B+1<<" ";
			}
		}
	}
	return 0;
}