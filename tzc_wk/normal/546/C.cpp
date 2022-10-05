#include <bits/stdc++.h>
using namespace std;
int n,k1,k2;
queue<int> q1,q2;
int main(){
	cin>>n;
	cin>>k1;
	for(int i=1;i<=k1;i++){
		int x;cin>>x;q1.push(x);
	}
	cin>>k2;
	for(int i=1;i<=k2;i++){
		int x;cin>>x;q2.push(x);
	}
	for(int i=1;i<=100000;i++){
		if(q1.empty()){
			cout<<i-1<<" "<<2<<endl;
			return 0;
		}
		if(q2.empty()){
			cout<<i-1<<" "<<1<<endl;
			return 0;
		}
		int a1=q1.front(),a2=q2.front();
		q1.pop(),q2.pop();
		if(a1>a2){
			q1.push(a2);
			q1.push(a1);
		}
		else{
			q2.push(a1);
			q2.push(a2);
		}
	}
	puts("-1");
}