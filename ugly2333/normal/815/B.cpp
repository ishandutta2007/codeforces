// CF 815B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int mod = 1000*1000*1000+7;
int a[222222],b[222222];
int Pow(int x,int k)
{
	if(k==0)
		return 1;
	LL res;
	res=Pow(x,k/2);
	res=(LL)(res*res)%mod;
	if(k&1)
		res=(LL)(res*x)%mod;
	return res;
}
int main()
{
	int n,i,f;
	LL lans,rans,c;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	if(n%4<2)
		f=-1;
	else
		f=1;
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	if(n==2){
		cout<<(a[1]+a[2])%mod<<endl;
		return 0;
	}
	if(n&1){
		for(i=1;i<n;i=i+1){
			if(i&1)
				a[i]+=a[i+1];
			else
				a[i]-=a[i+1];
		}
		n--;
	}
	for(i=1;i<=n;i=i+1){
		if(i&1)
			a[(i+1)/2]=a[i];
		else
			b[(i+1)/2]=a[i];
	}
	n/=2;
	lans=a[1];
	c=1;
	for(i=2;i<=n;i=i+1)
	{
		c=(LL)c*(n-i+1)%mod;
		c=(LL)c*Pow(i-1,mod-2)%mod;
		lans=(LL)(lans+c*a[i])%mod;
	}
	rans=b[1];
	c=1;
	for(i=2;i<=n;i=i+1)
	{
		c=(LL)c*(n-i+1)%mod;
		c=(LL)c*Pow(i-1,mod-2)%mod;
		rans=(LL)(rans+c*b[i])%mod;
	}
	//cout<<lans<<endl<<rans<<endl;
	cout<<(lans+f*rans+2*mod)%mod<<endl;
	return 0;
}
/*
16
985629174 189232688 48695377 692426437 952164554 243460498 173956955 210310239 237322183
96515847 678847559 682240199 498792552 208770488 736004147 176573082
*/