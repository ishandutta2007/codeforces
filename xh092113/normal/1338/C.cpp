#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const ll N = 1e5;

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
}
using namespace IO;

bool used[1000];
ll f[4] = {0,2,3,1};

ll calc(ll x,ll id){
//.cout<<"x="<<x<<" id="<<id<<" opt="<<opt<<endl;
	if(x == 1)return id;
	ll pre = 1,cur = 1,deg = 1;
	while(cur < x){
		pre = cur;
		deg <<= 2;
		cur = pre + deg;
	}
//cout<<"pre="<<pre<<" cur="<<cur<<" deg="<<deg<<endl;
	ll a = x + pre * 2;
	if(id == 1)return a;
	ll s = 0;
	while(deg){
		ll t = (a / deg) % 4;
//cout<<"t="<<t<<endl;
		s = s * 4 + f[t];
		deg >>= 2;
	}
	if(id == 2)return s;
	return s ^ a;
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("std.out","w",stdout);	
	/*int lim = 1;
	for(rg int i = 1;i <= 100;i++){
		int x = lim;
		used[x] = 1;
		
		for(rg int y = x + 1;;y++)if(!used[y] && !used[x^y]){
			used[y] = used[x^y] = 1;
			cout<<x<<endl<<y<<endl<<(x^y)<<endl;
			break;
		}
		while(used[lim])lim++;
	}*/
	int n = read();
	while(n--){
		ll x = read();	
		write(calc((x-1)/3+1,(x-1)%3+1)),putchar('\n');
	}
	return 0;	
}