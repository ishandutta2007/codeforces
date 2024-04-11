#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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

In bool id(int mask,int p){return mask & (1<<p);}
int bc(int x){
	int rt = 0;
	for(rg int i = 0;i <= 30;i++)rt += id(x,i);
	return rt;
}
In bool check(int p,int q){
//cout<<"check: p="<<p<<" q="<<q<<endl;
	if(p == q)return 1;
	if(p > q)return 0;
	int idp = (p & 1),idq = (q & 1);
	if(idp < idq)return 0;
	else if(idp == idq)return check(p >> 1,q >> 1);
	else{ // idp = 1,idq = 0
		int pos = 0;while(id(p,pos))pos++;
		int dp = (1ll << pos) - 1;
		if(dp == p){
			return p <= q && bc(p) >= bc(q);
		}
		else return check((p+dp) >> 1,q >> 1);
	}
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
// use long long
	int Tc = read();
	while(Tc--){
		int p = read(),q = read();
		if(p == q){puts("YES");continue;}
		for(rg int i = 30;i >= 0;i--){
			if(id(p,i) != id(q,i))break;
			if(id(p,i))p ^= (1<<i),q ^= (1<<i);
		}
		if(check(p,q))puts("YES");else puts("NO");
	}	
	return 0;
}