#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	int k=min(min(a+1,b),c-1);
	cout<<3*k<<endl;
}