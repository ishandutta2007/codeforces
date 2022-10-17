#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],it,s[100500],b[100500],cur;

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			b[i]=0;
			for(j=0;;j++){
				if(j==i){
					cout<<"NO\n";goto aaa;
				}
				if(a[i]%(i-j+1)){
					break;
				}
				b[i]++;
			}
		}
		cur=0;
		for(i=1;i<=n;i++){
			if(b[i]>cur){
				cout<<"NO\n";goto aaa;
			}
			cur++;
		}
		cout<<"YES\n";
		aaa:;
	}
}