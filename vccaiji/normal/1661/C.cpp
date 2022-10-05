#include<bits/stdc++.h>
using namespace std;
int _,n,h[310000];
long long solve(int m){
	long long sum=0,sum1=0;
	for(int i=1;i<=n;i++)sum+=m-h[i];
	for(int i=1;i<=n;i++)sum1+=(m-h[i])/2;
	long long t=(sum+2)/3;
	if(t>sum1)return 2*(sum-2*sum1)-1;
	if(t==0)return 0;
	return min(2*(sum-2*(t-1))-1,2*t);
}
int main(){
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>h[i];
		int maxx=0;
		for(int i=1;i<=n;i++)maxx=max(maxx,h[i]);
		cout<<min(solve(maxx),solve(maxx+1))<<endl;
	}
	return 0;
}