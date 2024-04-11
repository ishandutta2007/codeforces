#include "bits/stdc++.h"

using namespace std;
const int N = 300005, M = 3000005;

namespace IO {
	const int iL = 1<<18;
	char _buf[iL],*S,*T;
	#define gc (S==T?(T=(S=_buf)+fread(_buf,1,iL,stdin),S==T?0:*S++):*S++)
	template<class _Tp> inline void gi(_Tp&x){
		x=0;int f=1;char ch=gc;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
		while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=gc;x*=f;
	}
	char _o[25],*__o;
	template<class _Tp> inline void oi(_Tp x,char _y=0){
		if(x==0){putchar('0');if(_y)putchar(_y);}
		else {
			if(x<0) putchar('-'), x=-x;
			__o = _o+24; if(_y) *--__o = _y;
			while(x) *--__o = x%10+48, x/=10;
			fwrite(__o,1,_o+24-__o,stdout);
		}
	}
	inline void getc (int&x){
		char ch;
		for (ch=gc; ch>'z'||ch<'a'; ch=gc);
		x = ch-'a';
	}
} ;

int n,son[M][26],c,r[N],ans,id;

int merge (int x, int y, int deep){
	if (!x || !y) return x + y;
	int t = ++c; r[deep]--;
	for (int i=0; i<26; i++){
		if (son[x][i] == 0 && son[y][i] == 0) continue;
		son[t][i] = merge (son[x][i], son[y][i], deep);
	}
	return t;
}

void dfs (int x, int deep){
	int rt = 0;
	for (int i=0; i<26; i++) if (son[x][i]) {
		dfs (son[x][i], deep+1);
		rt = merge (rt, son[x][i], deep);
	}
	if (rt > 0) r[deep] --;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen ("778c.in","r",stdin);
		freopen ("778c.out","w",stdout);
	#endif
	using namespace IO;
	IO::gi(n);
	int u,v,ch;
	for (int i=1; i<n; i++) {
		gi(u), gi(v), getc(ch);
		son[u][ch] = v, r[i] = n;
	}
	r[n] = c = ans = n;
	dfs (1,1);
	for (int i=1; i<=n; i++){
		if (r[i] < ans) id = i;
		ans = min(ans, r[i]);
	}
	cout << ans << endl << id << endl;
	return 0;
}