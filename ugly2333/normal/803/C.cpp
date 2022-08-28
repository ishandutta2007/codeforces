//CF 803C
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
long long n,k,kk,g,m,i;
int main()
{
	int j;
	cin>>n>>k;
	if(k>=222222){
		cout<<-1<<endl;
		return 0;
	}
	kk=k+k*k;
	kk/=(long long)2;
	if(n<k){
		cout<<-1<<endl;
		return 0;
	}
	m=0;
	g=n;
	for(i=1;i<=n/i;i=i+1){
		if(n%i==0){
			if(n/i>=kk)
				m=max(m,i);
			if(i>=kk)
				m=max(m,n/i);
		}
	}
	if(m==0){
		cout<<-1<<endl;
		return 0;
	}
	for(j=1;j<k;j=j+1){
		cout<<(long long)j*m<<' ';
		n-=(long long)j*m;
	}
	cout<<n<<endl;
	return 0;
}