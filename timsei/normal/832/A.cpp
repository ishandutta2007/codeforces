using namespace std;
#include<bits/stdc++.h>
long long n,m,k,ans;
int main() {
	cin>>n>>k;
	ans=n/k;
	if(ans%2==1) puts("YES");else puts("NO");
}