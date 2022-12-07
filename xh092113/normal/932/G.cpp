#include<bits/stdc++.h>

using namespace std;

#define rg register
#define ll long long
#define In inline

const ll N = 1e6;
const ll mod = 1e9 + 7;

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

char t[N+5],s[N+5];
int n;
ll f[N+5],g[N+5],slink[N+5],diff[N+5];

struct PAM{
	int nx[N+5][26],fail[N+5],len[N+5];
	int cnt,last;
	void clear(){
		cnt = 1;
		fail[1] = fail[0] = 1;
		len[1] = -1;
	}
	void extend(char c,int n){
		int id = c - 'a';
		int p = last;
		while(s[n-len[p]-1] != s[n])p = fail[p];
		if(!nx[p][id]){
			cnt++;
			len[cnt] = len[p] + 2;
			int q = fail[p];
			while(s[n-len[q]-1] != s[n])q = fail[q];
			fail[cnt] = nx[q][id];
			diff[cnt] = len[cnt] - len[fail[cnt]];
			nx[p][id] = cnt;
			slink[cnt] = (diff[cnt] == diff[fail[cnt]] ? slink[fail[cnt]] : fail[cnt]);
		} 
		last = nx[p][id];
		p = last;
		while(p >= 2){
			g[p] = f[n-len[slink[p]]-diff[p]];
			if(diff[p] == diff[fail[p]])Inc(g[p],g[fail[p]]);
			if(!(n & 1))Inc(f[n],g[p]);
			p = slink[p];			
		}
	}
}P;

int main(){
//	freopen("CF932G.in","r",stdin);
//	freopen("CF932G.out","w",stdout);
	scanf("%s",t + 1);
	n = strlen(t + 1);
	if(n & 1){
		puts("0");
		return 0;
	}
	int _n = 0;
	for(rg int i = 1;(i << 1) <= n;i++){
		s[++_n] = t[i];
		s[++_n] = t[n+1-i];
	}
//cout<<s + 1 << endl;
	P.clear();
	f[0] = 1;
	for(rg int i = 1;i <= n;i++)P.extend(s[i],i);
	cout << f[n] << endl;
	return 0;	
}