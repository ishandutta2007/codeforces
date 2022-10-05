#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+100;
int n,L,a;
int t[MAXN],l[MAXN];
int ans=0;
int main(){
	cin>>n>>L>>a;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>l[i];
	}
	t[n+1]=L;
	for(int i=1;i<=n+1;i++){
		ans+=(t[i]-(t[i-1]+l[i-1]))/a;
	}
	cout<<ans<<endl;
}
//