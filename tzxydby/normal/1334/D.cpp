#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,l,r,base=0;
		cin>>n>>l>>r;
		for(long long i=(n-1)*2;i;base+=i,i-=2){
			for(long long j=max(base+1,l);j<=min(r,base+i);j++){
				if(j%2)cout<<n-i/2<<" ";
				else cout<<(j-base)/2+n-i/2<<" ";
			}
		}
		if(base==r-1)cout<<1;
		cout<<endl;
	}
}