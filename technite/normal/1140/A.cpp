#include <bits/stdc++.h>
using namespace std;
int n,i,a,e,d;
int main(){
	for(cin>>n,i=1;i<=n;i++){
	    cin>>a;
	    e=max(e,a);
	    if(e==i) d++;
	}
	cout<<d;
}