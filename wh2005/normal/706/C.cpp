#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s[100009],r[100009];
ll f[100009][2],c[100009];
void Mn(ll &x,ll y){
	if(x==-1||x>y) x=y;
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++){
		cin>>r[i];s[i]=r[i];
		reverse(r[i].begin(),r[i].end());
	}
	memset(f,-1,sizeof(f));
	f[1][0]=0,f[1][1]=c[1];
	for(int i=2;i<=n;i++){
		if(s[i]>=s[i-1]&&f[i-1][0]!=-1) Mn(f[i][0],f[i-1][0]);
		if(s[i]>=r[i-1]&&f[i-1][1]!=-1) Mn(f[i][0],f[i-1][1]);
		if(r[i]>=s[i-1]&&f[i-1][0]!=-1) Mn(f[i][1],f[i-1][0]+c[i]);
		if(r[i]>=r[i-1]&&f[i-1][1]!=-1) Mn(f[i][1],f[i-1][1]+c[i]);
	}
	if(f[n][1]!=-1) Mn(f[n][0],f[n][1]);
	printf("%lld",f[n][0]);
	return 0;
}