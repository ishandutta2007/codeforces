#include<bits/stdc++.h>
using namespace std;
int a,b;
bool tt[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>a>>b;
		int t=(a+b)/2;
		for(int i=min(a+t,2*(a+b)-a-t);i>=abs(a-t);i-=2)tt[i]=1;
		t=(a+b+1)/2;
		for(int i=min(a+t,2*(a+b)-a-t);i>=abs(a-t);i-=2)tt[i]=1;
		int cnt=0;
		for(int i=0;i<=a+b;i++)if(tt[i])cnt++;
		cout<<cnt<<endl;
		for(int i=0;i<=a+b;i++)if(tt[i])cout<<i<<' ';
		cout<<endl;
		for(int i=0;i<=a+b;i++)tt[i]=0;
	}
	return 0;
}