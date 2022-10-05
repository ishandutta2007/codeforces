#include <iostream>
using namespace std;
int n, m; 
int main(){
	cin>>n>>m;
	int cnt=0;
	while(n>0&&m>0){
		if(n<2&&m<2) break;
		if(n<m)	swap(n, m);
		n-=2;m++;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}