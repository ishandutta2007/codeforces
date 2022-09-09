#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int N=200050;
bitset<N> st[26],ans;
char s[N],t[N],p[N];
int n,m;
int main(){
	for(int i=0;i<26;++i)scanf("%i",&p[i]),p[i]--;
	scanf("%s %s",s,t);
	n=strlen(s);m=strlen(t);
	for(int i=0;i<n;++i)s[i]-='a';
	for(int i=0;i<m;++i)t[i]-='a';
	ans.set();
	for(int i=0;i<m;++i)st[t[i]][i]=1;
	for(int i=0;i<n;++i)ans&=(st[s[i]]|st[p[s[i]]])>>i;
	for(int i=0;i<=m-n;++i)printf(ans[i]?"1":"0");
	return 0;
}