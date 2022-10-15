#include <bits/stdc++.h>
using namespace std;
int64_t t,a,b,k;
int main(){
	for(cin>>t;t--;)
		cin>>a>>b>>k,
		cout<<(k/2)*(a-b)+(k%2?a:0)<<endl;;
}