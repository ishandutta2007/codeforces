#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int n,k;
int s[N],a[N];
void solve(){
	n=in(),k=in();
	for(int i=1;i<=k;i++)s[i]=in();
	bool flag=1;
	for(int i=3;i<=k;i++){
		if(s[i]-s[i-1]<s[i-1]-s[i-2])flag=0;	
	}
	if(k>1){
		int v=s[2]-s[1];
		if(1ll*v*(n-k+1)<s[1])flag=0;	
	}
	puts(flag?"Yes":"No");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}