#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long 

const int N = 1e6;
const ll mod1 = 998244353;
const ll mod2 = 1e9 + 7;

char s[N+5];
int n; 

namespace IO{
	In ll read(){	
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)x = -x,putchar('0');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	} 
}
using namespace IO;

ll p1[N+5],v1[N+5],p2[N+5],v2[N+5];

ll power(ll a,ll n,ll p){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return s;
}

/*
void manacher(){
	memset(r,0,sizeof(int) * (2 * n + 5));
	int tn = -1;
	t[++tn] = '$';
	for(rg int i = 1;i <= n;i++)t[++tn] = '*',t[++tn] = s[i];
	t[++tn] = '*';
	t[++tn] = '#';
	int c = 0,mx = 0;
cout<<t<<endl;
	for(rg int i = 1;i < tn;i++){
		
	}
}*/

namespace ModCalc{
	In void Inc(ll &x,ll y,ll mod){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y,ll mod){
		x -= y;if(x < 0)x += mod;
	}
	In ll Add(ll x,ll y,ll mod){
		Inc(x,y,mod);return x;
	}
	In ll Sub(ll x,ll y,ll mod){
		Dec(x,y,mod);return x;
	}
}
using namespace ModCalc;

struct str{
	ll h1,h2,len;
	str(ll _h1,ll _h2,ll _len){h1 = _h1,h2 = _h2,len = _len;}
	str(char c){h1 = c - 'a' + 1,h2 = c - 'a' + 1,len = 1;}
	str(){h1 = 0,h2 = 0,len = 0;}
	In friend bool operator == (str a,str b){
		return a.h1 == b.h1 && a.h2 == b.h2 && a.len == b.len;
	}
	In friend str operator + (str a,str b){
		ll _h1 = Add(a.h1 * p1[b.len] % mod1,b.h1,mod1);
		ll _h2 = Add(a.h2 * p2[b.len] % mod2,b.h2,mod2);
		return str(_h1,_h2,a.len + b.len);
	}
	In friend str operator - (str a,str b){
		ll _h1 = Sub(a.h1,b.h1 * p1[a.len-b.len] % mod1,mod1);
		ll _h2 = Sub(a.h2,b.h2 * p2[a.len-b.len] % mod2,mod2);
		return str(_h1,_h2,a.len - b.len);
	}
}pre[N+5],suf[N+5];

int main(){
	p1[0] = 1;
	for(rg int i = 1;i <= N;i++)p1[i] = p1[i-1] * 29 % mod1;
	p2[0] = 1;
	for(rg int i = 1;i <= N;i++)p2[i] = p2[i-1] * 29 % mod2;
	ll iv1 = power(29,mod1 - 2,mod1);
	ll iv2 = power(29,mod2 - 2,mod2);
	v1[0] = 1;
	for(rg int i = 1;i <= N;i++)v1[i] = v1[i-1] * iv1 % mod1;
	v2[0] = 1;
	for(rg int i = 1;i <= N;i++)v2[i] = v2[i-1] * iv2 % mod2; 
	int T = read();
	while(T--){
		scanf("%s",s + 1);
		n = strlen(s + 1);
		int i = 0;
		while(s[i+1] == s[n-i] && i + 1 <= n - i)i++;
		if(i + 1 > n - i){
			printf("%s\n",s + 1);
			continue;
		}
//cout<<i<<endl;
		int ans1 = i,ans2 = n - i + 1;
		int left = ans1,right = ans2;
		pre[0] = suf[n+1] = str();
		for(rg int i = 1;i <= n;i++)pre[i] = pre[i-1] + str(s[i]);
		for(rg int i = n;i >= 1;i--)suf[i] = suf[i+1] + str(s[i]);
		for(rg int i = ans1 + 1;i < ans2;i++){
		//	cout<<(pre[i] - pre[ans1]).h1<<" "<<(pre[i] - pre[ans1]).h2<<" "<<(pre[i] - pre[ans1]).len<<endl;
		//	cout<<(suf[ans1+1] - suf[i+1]).h1<<" "<<(suf[ans1+1] - suf[i+1]).h2<<" "<<(suf[ans1+1] - suf[i+1]).len<<endl;
			if((pre[i] - pre[ans1]) == suf[ans1+1] - suf[i+1])left = i;
		}
		for(rg int i = ans2 - 1;i > ans1;i--)if((suf[i] - suf[ans2]) == pre[ans2-1] - pre[i-1])right = i;
//cout<<left<<" "<<right<<endl;
		if(left - ans1 > ans2 - right){
			for(rg int i = 1;i <= left;i++)putchar(s[i]);
			for(rg int i = ans2;i <= n;i++)putchar(s[i]);		
		}
		else{
			for(rg int i = 1;i <= ans1;i++)putchar(s[i]);
			for(rg int i = right;i <= n;i++)putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}