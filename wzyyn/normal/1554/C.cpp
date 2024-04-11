#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int ask(int n,int m,int k,int B){
	if (k==-1) return B+1;
	if (n+1==(2<<k)) return B+(2<<k);
	if (!(m&(1<<k))) return ask(n-(n&(1<<k)),m,k-1,B+(n&(1<<k)));
	if (!(n&(1<<k))) return B;
	return ask(n-(1<<k),m-(1<<k),k-1,B);
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",ask(m,n,29,0));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}