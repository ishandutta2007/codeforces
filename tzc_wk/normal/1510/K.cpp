#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n;
int a[N+1];
bool ok(){
	for(int i=1;i<=2*n;i++)if(a[i]!=i)return false;
	return true;
}
void do1(){
	for(int i=1;i<=2*n;i+=2)swap(a[i],a[i+1]);
}
void do2(){
	for(int i=1;i<=n;i++)swap(a[i],a[n+i]);
}
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	int ans=1e9;
	if(ok())return puts("0"),0;
	for(int i=1;i<=4*n;i++){
		if(i&1)do1();
		else do2();
		if(ok())ans=min(ans,i);
	}
	for(int i=1;i<=4*n;i++){
		if(i&1)do1();
		else do2();
	}
	for(int i=1;i<=4*n;i++){
		if(i&1)do2();
		else do1();
		if(ok())ans=min(ans,i);
	}
	cout<<(ans==1e9?-1:ans);
	return 0;
}