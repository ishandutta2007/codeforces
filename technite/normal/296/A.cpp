#include<bits/stdc++.h>
using namespace std;
int n, b, a[1001];
int main () 
{
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>b;
		if(++a[b]>(n+1)/2){
		cout<<"NO";
		return 0;
		}
	}
	cout<<"YES";
}