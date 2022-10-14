#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int l = 0,r = 0,ok = 1;
		for(int i=0;i<n;i++){
			int c,v;
			cin>>c>>v;
			if(v-r>=0 && v-r<=c-l && c>=l){
				
			}else{
				ok =0 ;
			}
			l = c;
			r = v;
		}
		if(ok){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}