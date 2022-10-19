/*
Contest: Codeforces Round #664 (Div.1)
Problem: Codeforces 1394A
Author: tzc_wk
Time: 2020.8.12
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
int n=read(),k=read(),m=read(),a[100005],s[100005];
signed main(){
	fz(i,1,n) a[i]=read();
	sort(a+1,a+n+1);reverse(a+1,a+n+1);int pos=n+1;
	fz(i,1,n) if(a[i]<=m){
		pos=i;break;
	}
	if(pos==1){int sum=0;fz(i,1,n) sum+=a[i];cout<<sum<<endl;return 0;}
	pos--;fz(i,1,n) s[i]=s[i-1]+a[i];int ans=0;
	fz(i,0,pos){
		if(n-i-i*k>n-pos) continue;
		int lft=n-i-(i-1)*k;
//		cout<<i<<" "<<lft<<endl;
		if(lft<0) continue;
		if(lft>n-pos) lft=n-pos;
		ans=max(ans,s[i]+s[pos+lft]-s[pos]);
	}
	cout<<ans<<endl;
	return 0;
}