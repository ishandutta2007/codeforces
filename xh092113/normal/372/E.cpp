#include<bits/stdc++.h>

using namespace std;

#define N 1000
#define rg register
#define In inline
#define ll long long
#define eps 1e-9

const ll mod = (ll)1e9 + 7;

In ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
	while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;
	}
	In ll Add(ll x,ll y){
		Inc(x,y);return x;
	}
	In ll Sub(ll x,ll y){
		Dec(x,y);return x;
	}
}
using namespace ModCalc;

In int sgn(double x){
	return x < -eps ? -1 : x > eps;
}

struct vec{
	double x,y;
	vec(){}
	vec(double _x,double _y){x = _x,y = _y;}
	In friend vec operator + (vec a,vec b){
		return vec(a.x + b.x,a.y + b.y);
	}
	In friend vec operator - (vec a,vec b){
		return vec(a.x - b.x,a.y - b.y);
	}
	In friend vec operator * (vec a,double k){
		return vec(a.x * k,a.y * k);
	}
	In friend vec operator / (vec a,double k){
		return vec(a.x / k,a.y / k);
	}
	In friend double Dot(vec a,vec b){
		return a.x * a.x + b.y * b.y;
	}
	In friend double Cross(vec a,vec b){
		return a.x * b.y - a.y * b.x;
	}
	In friend bool equ(vec a,vec b){
		return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
	}
}p[N+5];

struct line{
	vec m,v;
	line(){}
	line(vec _m,vec _v){m = _m,v = _v;}
}l[N*N+5];
int ln;

In vec Adjust(vec a){
	int k;
	if((k = sgn(a.x)) < 0)a.x = -a.x,a.y = -a.y;
	else if(k == 0){
		if(sgn(a.y) > 0)a.y = -a.y;
	}
	return a;
}

In bool cmp(line a,line b){
	int k;
	if((k = sgn(a.m.x-b.m.x)) != 0)return k < 0;
	if((k = sgn(a.m.y-b.m.y)) != 0)return k < 0;
	return sgn(Cross(a.v,b.v)) == 1;
}

ll ans,n;
ll a[N*N+5],an;

void Count(){
//cout<<"an="<<an<<endl;
//for(rg int i = 1;i <= an;i++)cout<<a[i]<<" ";cout<<endl;
	ll cur = 1;
	for(rg int i = 1;i <= an;i++)cur = cur * (a[i] + 1) % mod;//* ((a[i]<<1) | 1) % mod;
	Dec(cur,1);
	for(rg int i = 1;i <= an;i++)Dec(cur,/*(a[i]<<1)%mod*/a[i]);
	Inc(ans,cur);
	an = 0;
}

int main(){
//	freopen("CF372E.in","r",stdin);
//	freopen("CF372E.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++){
		int a = read(),b = read(),c = read(),d = read();
		double x = (double)a / b,y = (double)c / d;
		double k = 1 / (x * x + y * y);
		p[i] = vec(x,y) * k;
	}
//for(rg int i = 1;i <= n;i++)cout<<p[i].x<<" "<<p[i].y<<endl;
	for(rg int i = 1;i < n;i++){
		for(rg int j = i + 1;j <= n;j++){
			ln++;
			l[ln].m = (p[i] + p[j]) / 2;
			l[ln].v = Adjust(p[i] - p[j]);
//if(l[ln].m.x == -0.75 && l[ln].m.y == 0)cout<<i<<" "<<j<<endl;
		}
	}
//puts("**********************************");
	sort(l + 1,l + ln + 1,cmp);
/*for(rg int i = 1;i <= ln;i++){
cout<<"i="<<i<<" m.x="<<l[i].m.x<<" m.y="<<l[i].m.y<<" v.x="<<l[i].v.x<<" v.y="<<l[i].v.y<<endl;
if(i > 1 && equ(l[i].m,l[i-1].m))cout<<"Good"<<endl;
}*/
	for(rg int i = 1;i <= ln;i++){
		if(i == 1 || !equ(l[i].m,l[i-1].m)){
			if(i != 1)Count();
			a[++an] = 1;
		}
		else if(sgn(Cross(l[i].v,l[i-1].v)) == 0)a[an]++;
		else a[++an] = 1;
	}
	Count();
	cout << ans << endl;
	return 0;
}