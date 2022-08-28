//CF 909F
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
int n,a[N];
int main()
{
	int i,x,y;
	cin>>n;
	for(i=n;i>=1;i=i-1){
		if(a[i])
			continue;
		x=1;
		while(x<=i){
			x<<=1;
		}
		if(x==i+1)
			break;
		while(x>i){
			y=(x-1)^i;
			if(!a[y]){
				a[i]=y,a[y]=i;
				break;
			}
			x>>=1;
		}
	}
	if(i)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(i=1;i<=n;i=i+1)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	
	if(n<=5||(n&(n-1))==0){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	a[1]=3,a[3]=1;
	a[2]=6,a[6]=2;
	a[4]=5,a[5]=4;
	if(n>=7)
		a[1]=7,a[7]=3;
	x=8;
	for(i=8;i<=n;i=i+1){
		a[i]=i+1;
		if(i==n||(i&(i+1))==0)
			a[i]=x,x=i+1;
	}
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}