#include<bits/stdc++.h>
long long n,s,a[300001],k,i;
main(){
	std::cin>>n;
	for(i=0;i<n;i++)	std::cin>>a[i];
	std::sort(a,a+n);
	for(i=0;i<n/2;i++)	s+=(a[i]+a[n-1-i])*(a[i]+a[n-1-i]);
	std::cout<<s;
	return 0;
}