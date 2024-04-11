#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e6;
const ll mod1 = 998244353,mod2 = 1e9 + 7;
const ll base = 29;

namespace ModCalc{
	void Inc(ll &x,ll y,ll mod){
		x += y;if(x >= mod)x -= mod;
	}
	void Dec(ll &x,ll y,ll mod){
		x -= y;if(x < 0)x += mod;
	}
	ll Add(ll x,ll y,ll mod){
		Inc(x,y,mod);return x;
	}
	ll Sub(ll x,ll y,ll mod){
		Dec(x,y,mod);return x;
	}
}
using namespace ModCalc;

In void write(ll x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x / 10);
	putchar('0' + x % 10);
}

char s[2*N+5];

struct SAM{
	int cnt,last,nx[2*N+5][26],fail[2*N+5],len[2*N+5];
	ll num[2*N+5];
	void clear(){
		fail[0] = -1;
	}
	void extend(char c){
		int id = c - 'a';
		int cur = ++cnt,p;
		num[cur] = 1;
		for(p = last;p != -1 && !nx[p][id];p = fail[p])nx[p][id] = cur;
		if(p == -1)fail[cur] = 0;
		else{
			int q = nx[p][id];
			if(len[q] == len[p] + 1)fail[cur] = q;
			else{
				int clone = ++cnt;
				len[clone] = len[p] + 1;
				fail[clone] = fail[q];
				memcpy(nx[clone],nx[q],sizeof(nx[clone]));
				fail[q] = fail[cur] = clone;
				for(;p != -1 && nx[p][id] == q;p = fail[p])nx[p][id] = clone;
			}
		}
		last = cur;
	}
	vector<int>link[2*N+5];
	void dfs(int u){
		for(rg int i = 0;i < link[u].size();i++){
			int v = link[u][i];
			dfs(v);
			num[u] += num[v];
		}
	}
	void prepro(){
		for(rg int i = 1;i <= cnt;i++)link[fail[i]].push_back(i);
		dfs(0);
	}
	ll query(char s[],int L,int n){ //nsL
		int u,i;
		ll ans = 0,curlen = 0;
		for(i = 1,u = 0;i <= n;i++){
			while(u && !nx[u][s[i]-'a'])u = fail[u],curlen = len[u];
			if(nx[u][s[i]-'a'])u = nx[u][s[i]-'a'],curlen++;
			if(i >= L){
				if(curlen >= L){
					while(len[fail[u]] >= L)u = fail[u];
					ans += num[u];
				}
			} 
		}
		return ans;
	}
}S;

ll pow1[N+5],pow2[N+5];

void prepro(){
	pow1[0] = pow2[0] = 1;
	for(rg int i = 1;i <= N;i++){
		pow1[i] = pow1[i-1] * base % mod1;
		pow2[i] = pow2[i-1] * base % mod2;
	}
}

struct str{
	ll h1,h2,len;
	str(){h1 = h2 = len = 0;}
	str(ll _h1,ll _h2,ll _len){h1 = _h1,h2 = _h2,len = _len;}
	str(char c){h1 = h2 = c - 'a',len = 1;}
	In friend str operator + (str a,str b){
		return str(Add(a.h1*pow1[b.len]%mod1,b.h1,mod1),Add(a.h2*pow2[b.len]%mod2,b.h2,mod2),a.len + b.len);
	}
	In friend bool operator == (str a,str b){
		return a.h1 == b.h1 && a.h2 == b.h2 && a.len == b.len;
	}
}h[N+5];

int calcT(char s[]){ //s
	h[0] = str();
	int n = strlen(s + 1);
	for(rg int i = 1;i <= n;i++)h[i] = h[i-1] + str(s[i]);
	for(rg int i = 1;i <= n;i++)if((h[i]+h[n]) == (h[n]+h[i]))return i;
}

int main(){
//	freopen("CF235C.in","r",stdin);
//	freopen("CF235C.out","w",stdout);
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	S.clear();
	for(rg int i = 1;i <= n;i++)S.extend(s[i]);
	S.prepro();
	int m;
	scanf("%d",&m);
	prepro();
	while(m--){
		scanf("%s",s + 1);
		int n = strlen(s + 1);
		bool b = 1;
		int T = calcT(s);
//cout<<"T="<<T<<endl;
		for(rg int i = 1;i < T;i++)s[n+i] = s[i];
		write(S.query(s,n,n+T-1));
		putchar('\n');
	}
}