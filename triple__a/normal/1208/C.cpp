#include<bits/stdc++.h>
using namespace std;

int lt[7][7];

int main(){
	int n;
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<4;++i){
		for (int j=0;j<4;++j){
			lt[i][j]=i*4+j;
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			cout<<lt[i%4][j%4]+(i/4)*16+(j/4)*4*n<<" ";
		}
		cout<<endl;
	}
	return 0;
}