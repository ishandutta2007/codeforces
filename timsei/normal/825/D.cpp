using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define int ll
#define N 3000001
int ne[N],n;
char s[N],t[N];
int yyq[3001],p[N];
int cnt=0;
int be[3001],af[3001];
int ans;
bool pd(int x) {
	if(x==0) return 1;
	for(int i=0;i<256;i++) p[i]=yyq[i]-be[i];
	if(x>=2){
		for(int i=0;i<256;i++) p[i]-=be[i]*(x-1);
	}
	int res=0;
	for(int i=0;i<256;i++) if(p[i]<0) res+=(-p[i]);
	if(res<=cnt) return 1;return 0;
}
int pos[N],tot;
char xx[N];
main() {
	scanf("%s",s);scanf("%s",t);
	int lent=strlen(t),wei=0;
	int lens=strlen(s);
	for(int i=0;i<lent;i++) {
		be[t[i]]++;
	}
	for(int i=0;i<lens;i++) {
		if(s[i]!='?')yyq[s[i]]++;else cnt++,pos[++tot]=i;
	}
	int l=0,r=lens;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(pd(mid)) {
			l=mid+1;ans=mid;
		}
		else r=mid-1;
	}
	if(ans>=1)
	for(int i=0;i<256;i++) p[i]=yyq[i]-be[i];
	if(ans>=2){
		for(int i=0;i<256;i++) p[i]-=be[i]*(ans-1);
	}
	for(int i=1;i<=tot;i++) xx[i]='a';
	int pp=1;
	for(int i=0;i<256;i++) {
		if(p[i]<0) {
			for(int j=1;j<=(-p[i]);j++) {
				xx[pp]=(char)(i);pp++;
			}
		}
	}
	for(int i=1;i<=tot;i++) {
		s[pos[i]]=xx[i];
	}
	puts(s);
}