#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair

const int N = 1e5;

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

int p[N+5],maxn,maxnn;
vector<pair<int,pii> >pos;

void ud(int x){
	if(x > maxn)maxn = x,maxnn = 1;
	else if(x == maxn)maxnn++;
}
In int check(int p,int x,int y){
//cout<<"check: p="<<p<<" x="<<x<<" y="<<y<<endl;
	int cur = maxnn - (x == maxn) - (y == maxn);
	if(cur > 0)return 0;
	if(x < y)swap(x,y);
	int xx = x % 2 == 0 ? x - 1 : x;
	if(xx >= y)return 0;
	return 1;
}
int solve(){
	maxn = 0;int rt = 0;
	for(auto p : pos)ud(p.se.fi),ud(p.se.se);
//cout<<"maxn="<<maxn<<" maxnn="<<maxnn<<endl;
	for(auto p : pos)rt += check(p.fi,p.se.fi,p.se.se);
	return rt;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int n = read();
	for(rg int i = 1;i <= n;i++)p[i] = read();
	p[0] = p[n+1] = 0;
	for(rg int i = 1;i <= n;i++)if(p[i-1] < p[i] && p[i+1] < p[i]){
		int x = i,y = i;
		while(x > 1 && p[x-1] <= p[x])x--;
		while(y < n && p[y+1] <= p[y])y++;
		pos.push_back(make_pair(i,make_pair(i-x,y-i)));
	}
	write(solve()),putchar('\n');
	return 0;
}