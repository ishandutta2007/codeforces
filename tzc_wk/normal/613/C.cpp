/*
Contest: -
Problem: Codeforces 613C
Author: tzc_wk
Time: 2020.9.14
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
int n=read(),a[30],sum=0,gcd;
int main(){
	fz(i,1,n) a[i]=read(),sum+=a[i]&1;
	gcd=a[1];fz(i,2,n) gcd=__gcd(gcd,a[i]);
	if(sum>=2){
		puts("0");
		fz(i,1,n) fz(j,1,a[i]) putchar(i-1+'a');
	}
	else if(sum==1){
		cout<<gcd<<endl;
		fz(i,1,gcd){
			int pos=0;
			fz(j,1,n) if(a[j]&1) pos=j;
			fz(j,1,n) if(j!=pos) fz(k,1,a[j]/gcd/2) putchar(j-1+'a');
			fz(j,1,a[pos]/gcd) putchar(pos-1+'a');
			fd(j,n,1) if(j!=pos) fz(k,1,a[j]/gcd/2) putchar(j-1+'a');
		}
	}
	else{
		cout<<gcd<<endl;
		fz(i,1,gcd/2){
			int pos=0;
			fz(j,1,n) fz(k,1,a[j]/gcd) putchar(j-1+'a');
			fd(j,n,1) fz(k,1,a[j]/gcd) putchar(j-1+'a');
		}
	}
	return 0;
}