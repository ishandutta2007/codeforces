#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%i",&n);
	long long a[n],s=0;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),s+=a[i]%2;
	if(s!=0)printf("First");
	else printf("Second");
}