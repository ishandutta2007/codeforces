#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define foR(i,j,k) for(int i=(j);i>=(k);i--) 
using namespace std;
int read() { int x; scanf("%d",&x); return x; }

const int MN=1e6+5,P=998244353;
int add(int x,int y) { return (x+y)%P; }
int sub(int x,int y) { return (x-y+P)%P; }
int mul(int x,int y) { return 1ull*x*y%P; }
void addmod(int &x,int y) { x=add(x,y); }
void submod(int &x,int y) { x=sub(x,y); }
void mulmod(int &x,int y) { x=mul(x,y); }

int a[MN],n,k; // range[i] : [0, i-1]
void works() {
	n=read(),k=read(); For(i,1,n) a[i]=read();
	int ans=1;
	For(i,1,k) mulmod(ans,i);
	For(i,k+1,n) {
		if(a[i-k]==-1) {
			mulmod(ans,i);
		} else {
			if(a[i-k]!=0) mul(ans,a[i-k]+k<=(i-1)); 
			else mulmod(ans,min(k+1,i) );
		}
	}
	For(i,n-k+1,n) {
		if(a[i]==-1) {
			; 
		} else {	
			if(a[i]!=0) mulmod(ans,0);
		}
	}
	cout<<ans<<endl;
}
int main() {
	int T=read();
	while(T--) {
		works();
	}
	return 0;
}