#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[5],k;
int main(){
	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a+3);
	cout<<2*k-(min(k,a[1]-a[0])+min(k,a[2]-a[1])); 
}