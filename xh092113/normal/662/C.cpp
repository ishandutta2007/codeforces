#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rg register
#define In inline

const ll N = 1048576;
const ll M = 100000;

In ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
	while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

In void calc(ll &x,ll &y,ll opt){
	if(opt == 1){
		ll X = x + y,Y = x - y;
		x = X,y = Y;
	}
	else{
		ll X = (x + y) >> 1,Y = (x - y) >> 1;
		x = X,y = Y;
	}
}

void FWT(ll a[],ll deg,ll opt){
	for(rg int n = 2;n <= deg;n <<= 1){
		int m = n >> 1;
		for(rg int i = 0;i < deg;i += n)
			for(rg int j = 0;j < m;j++)
				calc(a[i+j],a[i+j+m],opt);
	}
}

ll n,m,deg;
ll a[N+5],b[N+5],c[N+5],num[N+5];
ll situ[M+5];
char s[M+5];

int main(){
//	freopen("CF662C.in","r",stdin);
//	freopen("CF662C.out","w",stdout);
	n = read();m = read(),deg = 1ll << n;
	for(rg int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(rg int j = 1;j <= m;j++)situ[j] = ((situ[j]<<1) | (s[j]-'0'));
	}
	for(rg int i = 1;i <= m;i++)a[situ[i]]++;
	for(rg int i = 1;i < deg;i++)num[i] = num[i>>1] + (i&1);
	for(rg int i = 0;i < deg;i++)b[i] = min(num[i],num[deg-i-1]);
//for(rg int i = 0;i < deg;i++)cout<<b[i]<<" ";cout<<endl;
//for(rg int i = 0;i < deg;i++)cout<<a[i]<<" ";cout<<endl;
	FWT(a,deg,1);
	FWT(b,deg,1);
//for(rg int i = 0;i < deg;i++)cout<<b[i]<<" ";cout<<endl;
//for(rg int i = 0;i < deg;i++)cout<<a[i]<<" ";cout<<endl;
	for(rg int i = 0;i < deg;i++)c[i] = a[i] * b[i];
	FWT(c,deg,-1);
//for(rg int i = 0;i < deg;i++)cout<<c[i]<<" ";cout<<endl;
	ll ans = n * m;
	for(rg int i = 0;i < deg;i++)ans = min(ans,c[i]);
	cout << ans << endl;
	return 0;
}