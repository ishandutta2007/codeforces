#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
 
long long n,m;
cin>>n;
for(long long i=1;i*(i+1)<=n;++i){
	m=sqrt(n*2-i*(i+1));
	if(i*(i+1)+m*(m+1)==2*n){
		cout<<"YES";
		return 0;
	}
}
cout<<"NO";
return 0;
}