#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 300000
#define M 10

ll n,m,k,ans;
ll a[N+5],q[N+5];

inline ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

ll key(ll i){
	return a[i] - k * (i / m); 
}

ll cost(ll l,ll r){
	return a[r] - a[l] - k * ceil((double)(r - l) / m); 
}

int main(){
//	freopen("1197D.in","r",stdin);
//	freopen("1197D.out","w",stdout);
	n = read();m = read();k = read();
	ll i,j;
	for(i = 1;i <= n;i++)a[i] = read();
	for(i = 1;i <= n;i++)a[i] += a[i-1];
//for(i = 1;i <= n;i++)cout<<a[i]<<" ";cout<<endl;
	ans = 0;
	memset(q,-1,sizeof(q));
	q[0] = 0;
	for(i = 1;i <= n;i++){
		for(j = 0;j < m;j++)if(q[j] != -1){
			ans = max(ans,cost(q[j],i));
		}
		ll r = i % m;
		if(q[r] == -1 || key(i) < key(q[r]))q[r] = i;
	} 
	cout << ans << endl;
	return 0;
}