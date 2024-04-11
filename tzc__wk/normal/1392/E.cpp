/*
Contest: Codeforces Global Round 10
Problem: Codeforces 1392E
Author: tzc_wk
Time: 2020.8.16
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
int n=read();
int a[26][26];
signed main(){
	for(int i=2;i<=n;i++){
		a[1][i]=0;int stp=1ll<<(i-2),sum=0;
		int curx=1,cury=i;
		while(cury!=1){
			curx++;cury--;sum+=stp;
			a[curx][cury]=sum;
		}
	}
	for(int i=2;i<=n;i++){
		a[i][n]=0;int stp=1ll<<(i+n-3),sum=0;
		int curx=i,cury=n;
		while(curx!=n){
			curx++;cury--;sum+=stp;
			a[curx][cury]=sum;
		}
	}
	fz(i,1,n){
		fz(j,1,n) cout<<a[i][j]<<" ";
		puts("");
	}
	fflush(stdout);
	int q=read();
	while(q--){
		int k=read();
		vector<int> turn;
		fz(i,1,n-1){
			if(k==0){
				turn.push_back(n);continue;
			}
			int t=k&(-k);
			int f=log2(t);
			int pos=f+2-i;
//			cout<<pos<<endl;
			turn.push_back(pos);
			fz(j,pos,n-1) k-=1ll<<(i-2+j);
		}
		turn.push_back(n);
		int curx=1,cury=1;
		while(curx<=n){
			cout<<curx<<" "<<cury<<endl;
			while(cury<turn[curx-1]){
				cury++;cout<<curx<<" "<<cury<<endl;
			}
			curx++;
		}
		fflush(stdout);
	}
	return 0;
}
/*
1 2 4 8
2 4 8 16
4 8 16 32
8 16 32 64

0 0 0 0 0
1 2 4 8 0
4 8 16 16 0
12 24 32 32 0
32 48 64 64 0
*/