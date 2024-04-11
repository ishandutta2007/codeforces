/*
Contest: Codeforces Round #664 (Div.1)
Problem: Codeforces 1394C
Author: tzc_wk
Time: 2020.8.13
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
int n=read();
int x[300005],y[300005];
struct seg{
	int l,r;
	seg(){}
	seg(int _l,int _r){l=_l;r=_r;}
	friend seg operator &(seg a,seg b){
		if(a.r<b.l||b.r<a.l) return seg(1e6+1,1e6+1);
		return seg(max(a.l,b.l),min(a.r,b.r));
	}
};
inline pii check(int mid){
	seg a(0,1e6),b(0,1e6),c(-1e6,1e6);
	fz(i,1,n) a=a&seg(x[i]-mid,x[i]+mid);
	fz(i,1,n) b=b&seg(y[i]-mid,y[i]+mid);
	fz(i,1,n) c=c&seg(x[i]-y[i]-mid,x[i]-y[i]+mid);
	if(a.l==1000001||b.l==1000001||c.l==1000001) return pii(1000001,1000001);
	seg d=seg(a.l-b.r,a.r-b.l)&c;
	if(d.l==1000001) return pii(1000001,1000001);
	int x=min(a.r,b.r+c.r);
	int y=min(b.r,x-c.l);
	return pii(x,y);
}
int main(){
	fz(i,1,n){
		string s;cin>>s;
		int _x=0,_y=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='N') _x++;
			else _y++;
		}
		x[i]=_x;y[i]=_y;
//		cout<<_x<<" "<<_y<<endl;
	}
	int l=0,r=1000000,ansx=0,ansy=0,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		pii p=check(mid);
		if(p.fi==1000001) l=mid+1;
		else r=mid-1,ans=mid,ansx=p.fi,ansy=p.se;
	}
	cout<<ans<<endl;
	fz(i,1,ansx) cout<<'N';fz(i,1,ansy) cout<<'B';
	return 0;
}