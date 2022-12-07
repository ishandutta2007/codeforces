#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=500005;
char s[N];
int n,a[N*2],b[N*2];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,N-n,N+n) a[i]=b[i]=0;
	int p=N;
	For(i,1,n)
		if (s[i]=='1')
			++b[p],++p;
		else ++a[p],--p;
	p=N;
	For(i,1,n){
		//cout<<p<<' '<<a[p]<<' '<<b[p]<<endl;
		if (a[p]&&(!b[p]||b[p-1]>=1))
			putchar('0'),--a[p],--p;
		else putchar('1'),--b[p],++p;
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}