#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,f[300500],q,l,r;
char s[300500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>q>>s+1;
		for(i=1;i<=n;i++){
			if(i&1){
				if(s[i]=='+'){
					f[i]=f[i-1]+1;
				}
				else{
					f[i]=f[i-1]-1;
				}
			}
			else{
				if(s[i]=='+'){
					f[i]=f[i-1]-1;
				}
				else{
					f[i]=f[i-1]+1;
				}
			}
		}
		while(q--){
			cin>>l>>r;
			if((r-l+1)&1){
				cout<<1<<'\n';
			}
			else{
				if(f[r]==f[l-1]){
					cout<<0<<'\n';
				}
				else{
					cout<<2<<'\n';
				}
			}
		}
	}
}