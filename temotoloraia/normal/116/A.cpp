#include<iostream> 
using namespace std; int main(){ int n, a, b, i, k=0, k1=0; cin>>n; for(i=0;i<n;i++)	{ cin>>a>>b; k=k-a+b; if(k>=k1)k1=k;	} cout<<k1; }