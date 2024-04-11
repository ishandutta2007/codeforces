#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n%2==0)	return puts("-1"),0;
	for(int i=0;i<n;i++)	cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)	cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)	cout<<i*2%n<<" ";
	cout<<endl;
}