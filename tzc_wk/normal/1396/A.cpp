/*
Contest: Codeforces Round #666 (Div.1)
Problem: Codeforces 1396A
Author: tzc_wk
Time: 2020.8.30
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
int n=read(),a[100005],b[100005];
signed main(){
	fz(i,1,n) a[i]=read();
	if(n==1){
		puts("1 1");cout<<-a[1]<<endl;
		puts("1 1\n0");puts("1 1\n0");
		return 0;
	}
	fz(i,1,n){
		b[i]=n-(a[i]+n*2000000000)%n;
	}
	cout<<1<<" "<<1<<endl<<b[1]<<endl;
	a[1]+=b[1];
	cout<<2<<" "<<n<<endl;
	fz(i,2,n){
		cout<<((a[i]+n*2000000000)%n)*(n-1)<<" ";
		a[i]+=((a[i]+n*2000000000)%n)*(n-1);
	}
	puts("");
	cout<<1<<" "<<n<<endl;
	fz(i,1,n) cout<<-a[i]<<" ";
	return 0;
}