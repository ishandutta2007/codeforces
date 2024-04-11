/*
Contest: Grakn Forces 2020
Problem: Codeforces 1408D
Author: tzc_wk
Time: 2020.9.30
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
int a[2005],b[2005],c[2005],d[2005];
int mx[1000005];
int main(){
	fz(i,1,n) a[i]=read(),b[i]=read();
	fz(i,1,m) c[i]=read(),d[i]=read();
	fz(i,1,n) fz(j,1,m){
		if(a[i]<=c[j]&&b[i]<=d[j]){
			mx[c[j]-a[i]+1]=max(mx[c[j]-a[i]+1],d[j]-b[i]+1);
		}
	}
	int cur=0,ans=0x3f3f3f3f;
	for(int i=1000001;i>=0;i--){
		ans=min(ans,cur+i);
		cur=max(cur,mx[i]);
	}
	printf("%d\n",ans);
	return 0;
}