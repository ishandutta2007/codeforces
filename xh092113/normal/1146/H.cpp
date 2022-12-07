#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rg register
#define In inline

const ll N = 300;

typedef pair<ll,ll>pll;

In ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
	while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

struct vec{
	ll x,y;
	vec(){}
	vec(ll _x,ll _y){x = _x,y = _y;}
	In friend vec operator - (vec a,vec b){
		return vec(a.x - b.x,a.y - b.y);
	}
	In friend ll Cross(vec a,vec b){
		return a.x * b.y - a.y * b.x;
	}
	In friend bool InUpper(vec a){
		return a.y > 0 || (a.y == 0 && a.x > 0);
	}
}p[N+5];

In bool cmp(pll i,pll j){
	vec a = p[i.second] - p[i.first],b = p[j.second] - p[j.first];
	bool k1 = InUpper(a),k2 = InUpper(b);
	if(k1 != k2)return k1 < k2;
	return Cross(a,b) > 0;
}

ll f[N+5][N+5][7];
ll n;
pll seg[N*N+5];

int main(){
//	freopen("CF1146H.in","r",stdin);
//	freopen("CF1146H.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++){
		ll x = read(),y = read();
		p[i] = vec(x,y);
	}	
	int cnt = 0;
	for(rg int i = 1;i <= n;i++)
		for(rg int j = 1;j <= n;j++)if(i != j)seg[++cnt] = make_pair(i,j);
	sort(seg + 1,seg + cnt + 1,cmp);
	for(rg int i = 1;i <= n;i++)f[i][i][1] = 1;
	for(rg int k = 1;k <= cnt;k++){
		int u = seg[k].first,v = seg[k].second;
		for(rg int i = 1;i <= n;i++)
			for(rg int j = 1;j <= 5;j++)f[i][v][j+1] += f[i][u][j];
	}	
	ll ans = 0;
	for(rg int i = 1;i <= n;i++)ans += f[i][i][6];
	cout << ans << endl;
	return 0;
}