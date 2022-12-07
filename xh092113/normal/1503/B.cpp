#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define fi first
#define se second

const int N = 100;

typedef pair<int,int> pii;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

pii pos1[N*N+5];int cnt1,p1;
pii pos2[N*N+5];int cnt2,p2;
int n;

void report(int c,int i,int j){
	cout<<c<<" "<<i<<" "<<j<<endl;
	fflush(stdout);
}
void solve1(pii pos[],int type,int &p,int &cnt){
	while(p < cnt){
		int c = read();
		if(c != 3)p++,report(3,pos[p].fi,pos[p].se);
		else p++,report(3 - type,pos[p].fi,pos[p].se);
	}
}
void solve(){
	p1 = p2 = 0;
	rep(i,1,n)rep(j,1,n){
		if((i+j) & 1)pos1[++cnt1] = mp(i,j);
		else pos2[++cnt2] = mp(i,j);
	}
//rep(i,1,cnt1)cout<<pos1[i].fi<<" "<<pos1[i].se<<endl;
//cout<<endl;
//rep(i,1,cnt2)cout<<pos2[i].fi<<" "<<pos2[i].se<<endl;
	while(p1 < cnt1 && p2 < cnt2){
		int c = read();
		if(c != 1)p1++,report(1,pos1[p1].fi,pos1[p1].se);
		else
		if(c != 2)p2++,report(2,pos2[p2].fi,pos2[p2].se);
//cout<<p1<<" "<<p2<<endl;
	}
	if(p1 == cnt1)solve1(pos2,1,p2,cnt2);
	else solve1(pos1,2,p1,cnt1);
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	n = read();
	solve();
	return 0;
}