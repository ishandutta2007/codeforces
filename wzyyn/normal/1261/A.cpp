#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm> 
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
char s[2005],t[2005];
int n,k;
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int p=0;
	For(i,1,k-1) t[++p]='(',t[++p]=')';
	For(i,1,n/2-k+1) t[++p]='(';
	For(i,1,n/2-k+1) t[++p]=')';
	printf("%d\n",n);
	For(i,1,n)
		For(j,i,n) if (t[i]==s[j]){
			reverse(s+i,s+j+1);
			printf("%d %d\n",i,j);
			break;
		}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}