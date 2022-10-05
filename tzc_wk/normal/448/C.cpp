/*
Contest:
Problem:
Author: tzc_wk
Time:
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
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),a[5005];
inline int solve(int l,int r,int p){
	if(l>r) return 0;
	int mn=0x3f3f3f3f;
	fz(i,l,r) mn=min(mn,a[i]);
	int pre=l,ans=mn-p;
	fz(i,l,r){
		if(a[i]==mn){
			ans+=solve(pre,i-1,mn);
			pre=i+1;
		}
	}
	ans+=solve(pre,r,mn);
	return min(ans,r-l+1);
}
signed main(){
	fz(i,1,n) a[i]=read();
	cout<<solve(1,n,0)<<endl;
	return 0;
}