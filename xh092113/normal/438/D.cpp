#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000
#define ll long long 
#define glc(x) x << 1
#define grc(x) (x << 1) + 1
struct point{
	ll maxn;
	ll sum;
	int l;
	int r;
};
ll n,m,i,id,l,r,p,w,x;
point t[4*N+5];
ll a[N+5];

inline ll read(){
	ll s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')w = -1ll;ch = getchar();}
	while(isdigit(ch)){s = 10ll * s + ch - '0';ch = getchar();}
	return s * w;
}

inline void write(ll x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x/10);
	putchar('0' + x % 10);	
}

void pushup(int d){
	t[d].maxn = max(t[glc(d)].maxn,t[grc(d)].maxn);
	t[d].sum = t[glc(d)].sum + t[grc(d)].sum;
}

void build(int d,int l,int r){
	int m = (l + r) >> 1;                   
	t[d].l = l;
	t[d].r = r;
	if(l == r){
		t[d].maxn = a[l];
		t[d].sum = a[l];
		return;
	}
	build(glc(d),l,m);
	build(grc(d),m+1,r);
	pushup(d);
}

void ud1(int d,int l,int r,ll p){
	int m = (t[d].l + t[d].r) >> 1;
	if(t[d].maxn < p)return;
	if(t[d].l == t[d].r){t[d].maxn %= p;t[d].sum = t[d].maxn;return;}
	if(r <= m){ud1(glc(d),l,r,p);pushup(d);return;}
	else if(l > m){ud1(grc(d),l,r,p);pushup(d);return;}
	else ud1(glc(d),l,m,p);ud1(grc(d),m+1,r,p);pushup(d);return;
}

void ud2(int d,int x,ll w){
	int m = (t[d].l + t[d].r) >> 1;
	if(t[d].l == t[d].r){t[d].maxn = t[d].sum = w;return;}
	if(x <= m){ud2(glc(d),x,w);pushup(d);return;}
	else{ud2(grc(d),x,w);pushup(d);return;}
}

ll query(int d,int l,int r){
	int m = (t[d].l + t[d].r) >> 1;
	if(t[d].l == l && t[d].r == r)return t[d].sum;
	if(r <= m)return query(glc(d),l,r);
	else if(l > m)return query(grc(d),l,r);
	else return query(glc(d),l,m) + query(grc(d),m+1,r);
}

int main(){
//  	freopen("L.in","r",stdin);
//	freopen("L.out","w",stdout);
	n = read();m = read();
//cout<<n<<" "<<m<<" "<<endl;
	for(i = 1;i <= n;i++)a[i] = read();
	build(1,1,n);
	while(m--){
		id = read();
//cout<<"id="<<id<<endl;
		switch(id){
			case 1:l = read();r = read();write(query(1,l,r));putchar('\n');break;
			case 2:l = read();r = read();p = read();ud1(1,l,r,p);break;
			case 3:x = read();w = read();ud2(1,x,w);
		}	
//for(i = 1;i <= n;i++)cout<<query(1,i,i)<<" ";cout<<endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}