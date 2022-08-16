#include<iostream>
#include<stdlib.h>
using namespace std;
#define  ll long long int 
ll min(ll a,ll b){
	if(a<b)
		return a;
	return b;
}
int main(){
	ll n,x,y;
	cin>>n>>x>>y;
	ll a[10000003];
	a[0]=0;
	a[1]=x;
	for (int i = 2; i <=n; ++i)
	{
		if(i%2){
			a[i]=min(a[i-1]+x,a[i/2+1]+y+x);
		}
		else{
			a[i]=min(a[i-1]+x,a[i/2]+y);
		}
	}
	cout<<a[n];
}