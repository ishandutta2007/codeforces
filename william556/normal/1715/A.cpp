#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
void solve(){
	int n=in(),m=in();
	if(n+m==2)cout<<0<<endl;
	else cout<<n+m-2+min(n,m)<<endl;
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}