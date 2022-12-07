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
const int N=1000005;
int n,k,T,vi[1<<20|5],f[N];
char s[N],t[N];
void solve(){
	++T;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	For(i,1,n) s[i]^=1;
	int p=max(k-19,1);
	For(i,1,p-1) t[i]='0';
	f[n+1]=0;
	Rep(i,n,1) f[i]=(s[i]=='0'?f[i+1]+1:0);
	For(i,1,n-k+1) if (f[i]>=p-1){
		int v=0;
		For(j,i+p-1,i+k-1)
			if (s[j]=='1')
				v|=1<<((i+k-1)-j);
		//cout<<i<<' '<<f[i]<<' '<<v<<endl; 
		vi[v]=T;
	}
	int x=0;
	for (;vi[x]==T;++x);
	if (x>=(1<<(k-p+1))) puts("NO");
	else{
		puts("YES");
		For(i,p,k) t[i]=((x>>(k-i))&1?'1':'0');
		t[k+1]=0;
		printf("%s\n",t+1);
	}
}
int main(){
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}