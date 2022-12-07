#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int Add(int x,int y){
	int z=0,v=1;
	for (;x||y;){
		z+=((x+y)%k+k)%k*v;
		x/=k; y/=k; v*=k;
	}
	return z;
}
int Minus(int x,int y){
	int z=0,v=1;
	for (;x||y;){
		z+=((x-y)%k+k)%k*v;
		x/=k; y/=k; v*=k;
	}
	return z;
}
int y=233;
bool check(int x){
	cout<<x<<endl;
	cin>>x;
	return x;
}
/*(g=y-x)*/
void solve(){
	scanf("%d%d",&n,&k);
	if (check(0)) return;
	int v=0;
	for (int i=1;i<n;i++){
		if (i&1) v=Minus(v,Minus(i,i-1));
		else v=Add(v,Minus(i,i-1)); 
		if (check(v)) return;
		v=0;
	}
	assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}