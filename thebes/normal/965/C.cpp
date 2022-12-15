#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,d,ans,tp,p=1;

int main(){
	cin>>n>>m>>k>>d;
	for(int i=1;i<=d&&p<=n;i++,p+=m)ans=max(ans,min(k,n/p)*i);
	cout<<ans<<endl;
}