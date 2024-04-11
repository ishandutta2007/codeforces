//CF 862C
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
const int N = 111111;
int main()
{
	int n,k,x,y;
	cin>>n>>k;
	if(n==2){
		if(!k)
			cout<<"NO"<<endl;
		else
			cout<<"YES\n0 "<<k<<endl;
		return 0;
	}
	cout<<"YES\n";
	x=N;
	while(n>4||n==3){
		n-=2;
		cout<<2*x<<' ';
		cout<<2*x+1<<' ';
		x++;
		k^=1;
	}
	if(n==1){
		cout<<k<<endl;
		return 0;
	}
	if(n==4){
		if(k!=1){
			cout<<2*x<<' ';
			cout<<2*x+1<<' ';
			cout<<0<<' ';
			cout<<(k^1)<<endl;
		}
		else{
			cout<<4*x<<' ';
			cout<<4*x+2<<' ';
			cout<<0<<' ';
			cout<<(k^2)<<endl;
		}
	}
	return 0;
}