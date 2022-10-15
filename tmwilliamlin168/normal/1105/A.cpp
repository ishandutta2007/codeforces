#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,b;
	cin>>x;
	int a[x];
	for(int i=0;i<x;i++)cin>>a[i];
	int sum=0,v=100000;
	for(int i=1;i<=100;i++){
		sum=0;
		for(int j=0;j<x;j++){if(abs(a[j]-i)>1)sum+=abs(a[j]-i)-1;
			
		}
		int s=v;
		v=min(v,sum);
		if(s!=v)b=i;
	}
	cout<<b<<' '<<v;
	return 0;
}