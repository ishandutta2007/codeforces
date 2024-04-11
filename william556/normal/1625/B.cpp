#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int t,n;
int a[N],las[N];
void solve(){
	n=in();
	int ans=-1;
	for(int i=1;i<=n;i++){
		a[i]=in();
		if(las[a[i]])ans=max(ans,las[a[i]]+n-i);
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++)las[a[i]]=0;
	cout<<ans<<endl;
}
int main(){
	t=in();
	while(t--)solve();
	return 0;
}