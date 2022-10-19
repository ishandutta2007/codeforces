#include<bits/stdc++.h>
using namespace std;
int n,m,q,a,b,i,j,z,y[1790];
string s,t;
int main(){
	cin>>n>>m>>q>>s>>t;
	for(i=n-1;i>=0;i--){
		for(j=0,z=1;j<m;j++)s[i+j]!=t[j]?z=0:0;
		y[i]=y[i+1]+z;
	}
	for(;q--;){
		cin>>a>>b;a--;
		cout<<(b>=m&&b-a>=m?y[a]-y[b-m+1]:0)<<endl;
	}
}