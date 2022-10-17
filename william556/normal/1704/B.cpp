#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
int n,x;
int a[200005];
void solve(){
	n=in(),x=in()<<1;
	for(int i=1;i<=n;i++)a[i]=in();
	int ans=-1;
	for(int i=1,j;i<=n;i=j){
		int mx=0,mn=1e9;
		for(j=i;j<=n&&a[j]-mn<=x&&mx-a[j]<=x;j++){
			mx=max(mx,a[j]),mn=min(mn,a[j]);
		}
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}