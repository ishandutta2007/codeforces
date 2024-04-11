#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500],it,l,r;

bool chk(){
	int l=1,r=it;
	while(l<r){
		if(b[l]!=b[r]){
			return 0;
		}
		l++;r--;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		l=1;r=n;
		while(l<r){
			if(a[l]==a[r]){
				l++;r--;
			}
			else{
				
				it=0;
				for(i=1;i<=n;i++){
					if(a[i]!=a[l]){
						b[++it]=a[i];
					}
				}
				if(chk()){
					cout<<"YES\n";
					goto aaa;
				}
				
				it=0;
				for(i=1;i<=n;i++){
					if(a[i]!=a[r]){
						b[++it]=a[i];
					}
				}
				if(chk()){
					cout<<"YES\n";
					goto aaa;
				}
				cout<<"NO\n";
				goto aaa;
			}
		}
		cout<<"YES\n";
		continue;
		aaa:;
		
	}
}