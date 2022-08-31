#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n/2;i++) ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	cout<<ans<<endl;
	return 0;
}