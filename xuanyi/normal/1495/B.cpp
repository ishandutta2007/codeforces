// author: xay5421
// created: Wed Mar 10 20:12:09 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,p[N],up1[N],up2[N],dw1[N],dw2[N],pre[N],suf[N];
int main(){
	rd(n);
	rep(i,1,n)rd(p[i]);
	int ans=0;
	rep(i,2,n){
		if(p[i]<p[i-1])up1[i]=up1[i-1]+1;
		if(p[i]>p[i-1])dw1[i]=dw1[i-1]+1;
	}
	per(i,n-1,1){
		if(p[i]<p[i+1])up2[i]=up2[i+1]+1;
		if(p[i]>p[i+1])dw2[i]=dw2[i+1]+1;
	}
	rep(i,1,n){
		pre[i]=max(pre[i-1],max(up1[i],up2[i-1]));
	}
	per(i,n,1){
		suf[i]=max(suf[i+1],max(up2[i],up1[i+1]));
	}
	rep(i,2,n-1){
		if(p[i]>p[i-1]&&p[i]>p[i+1]){
			int l=i,r=i;
			while(l>1&&p[l]>p[l-1])--l;
			while(r<n&&p[r]>p[r+1])++r;
			int len1=i-l,len2=r-i,t=max(len1,len2);
			if(max(pre[l],suf[r])<t){
				if(len1==len2&&len1%2==0){
					++ans;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}