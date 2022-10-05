#include <bits/stdc++.h>
using namespace std;
void solve(int l,int r){
	int C=(l&1)*2+(r&1);
	if(C==0)cout<<(r-(r-l)/2)<<endl;
	if(C==1)cout<<(-(r+1-l)/2)<<endl;
	if(C==2)cout<<(r+1-l)/2<<endl;
	if(C==3)cout<<((r+1-l)/2-r)<<endl;
}
int main(){
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		solve(l,r);
	}
}//