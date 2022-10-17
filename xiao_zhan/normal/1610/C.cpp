#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500],l,r,md,res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		
		l=0;r=n;res=0;
		for(i=1;i<=n;i++){
			cin>>b[i]>>a[i];
		}
		
		while(l<=r){
			md=(l+r)/2;
			k=0;
			for(i=1;i<=n;i++){
				if(k==n)break;
				
				if(a[i]>=k&&b[i]>=(md-k-1)){
					k++;
				}
			}
			if(k>=md){
				res=max(res,md);
				l=md+1;
			}
			else{
				r=md-1;
			}
		}
		cout<<res<<'\n';
	}
}