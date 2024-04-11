#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
typedef long long ll;
int n,k,b;
ll s;
ll a[100005];
void solve(){
	n=in(),k=in(),b=in();scanf("%lld",&s);
	for(int i=1;i<=n;i++)a[i]=0;
	a[1]=(ll)k*b;s-=a[1];
	if(s<0){
		puts("-1");
		return;
	}
	for(int i=1;i<=n;i++){
		ll v=min((ll)k-1,s);
		s-=v;a[i]+=v;	
	}
	if(s!=0){
		puts("-1");
		return;	
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]),a[i]=0;
	puts("");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}