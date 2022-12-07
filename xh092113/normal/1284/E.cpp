#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rg register
#define In inline

const ll N = 2500;

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
	In friend vec operator + (vec a,vec b){
		return vec(a.x + b.x,a.y + b.y);
	}
	In friend vec operator - (vec a,vec b){
		return vec(a.x - b.x,a.y - b.y);
	}
	In friend ll Dot(vec a,vec b){
		return a.x * b.x + a.y * b.y;
	}
	In friend ll Cross(vec a,vec b){
		return a.x * b.y - a.y * b.x;
	}
	In friend bool InUpper(vec a){
		return a.y > 0 || (a.y==0&&a.x>0);
	}
}p[N+5];

struct ang{ //
	vec v;ll r; 
	ang(){}
	ang(vec _v,ll _r){v = _v,r = _r;}
	In friend ang Rot180(ang a){
		if(InUpper(a.v))a.r++;
		a.v.x = -a.v.x;
		a.v.y = -a.v.y;
		return a;
	}
	In friend bool operator < (ang a,ang b){
		if(a.r != b.r)return a.r < b.r;
		bool k1 = InUpper(a.v),k2 = InUpper(b.v);
		if(k1 != k2)return k1 < k2;
		return Cross(a.v,b.v) > 0;
	}
};

ll n;
ang a[2*N+5];

In ll C2(ll x){return x * (x - 1) / 2;}

In ll C4(ll x){return x * (x - 1) * (x - 2) * (x - 3) / 24;}

In ll sum1(ll x){return x * (x + 1) / 2;}

In ll sum2(ll x){return x * (x + 1) * ((x<<1)|1) / 6;}

In ll sum(ll x){
//cout<<"sum: x="<<x<<" "<<((sum2(x) - sum1(x)) >> 1)<<endl;
	return (sum2(x) - sum1(x)) >> 1;
}

ll calc(ll id){
//cout<<"calc: id="<<id<<endl;
	ll cnt = 0;
	for(rg int i = 1;i <= n;i++)if(i != id)a[++cnt] = ang(p[i] - p[id],0);
	sort(a + 1,a + cnt + 1);
	ll m = cnt;
	for(rg int i = 1;i <= m;i++)a[++cnt] = ang(a[i].v,1);
	a[++cnt] = ang(vec(-1,0),2); //
//for(rg int i = 1;i <= cnt;i++)cout<<a[i].v.x<<" "<<a[i].v.y<<" "<<a[i].r<<endl;
	int l = 0,r = 0;
	ll ans = 0;
	for(rg int i = 1;i <= m;i++){
		ang al = Rot180(a[i]);
		while(a[l] < al)l++;
		r = i + m - 1;
		ans += sum(r - l);
	}
	return ans;
}

int main(){
//	freopen("CF1284E.in","r",stdin);
//	freopen("CF1284E.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++){
		ll x = read(),y = read();
		p[i] = vec(x,y);
	}
	ll all = n * C4(n - 1);
	ll ans = 0;
	for(rg int i = 1;i <= n;i++)ans += calc(i);
	ans = all - ans;
	cout << ans << endl;
	return 0;
}