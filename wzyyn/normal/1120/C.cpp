#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=5005;
int n,A,B,la[30];
int lcp[N][N],f[N];
char s[N];
int main(){
	scanf("%d%d%d%s",&n,&A,&B,s+1);
	memset(f,100,sizeof(f));
	f[0]=0;
	For(i,0,25) la[i]=n+1;
	Rep(i,n,1) Rep(j,n,1)
		lcp[i][j]=(s[i]==s[j]?lcp[i+1][j+1]+1:0);
	For(i,1,n){
		f[i]=min(f[i],f[i-1]+A);
		int len=0;
		For(j,1,i-1) len=max(len,min(i-j,lcp[j][i]));
		For(p,i,i+len-1) f[p]=min(f[p],f[i-1]+B);
	}
	printf("%d\n",f[n]);
}