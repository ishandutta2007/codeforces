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
#define y1 fdhjksa
using namespace std;
int n,q[5005];
char a[1005],b[1005];
void flip(int x){
	q[++*q]=x;
	reverse(a+1,a+x+1);
	For(i,1,x) a[i]^=1;
}
void solve(){
	scanf("%d%s%s",&n,a+1,b+1);
	*q=0;
	Rep(i,n,1)
		if (a[i]!=b[i]){
			For(j,1,i-1)
				if (a[j]==b[i]){
					flip(j);
					flip(i);
					break;
				}
			if (a[i]!=b[i])
				flip(i);
		}
	printf("%d ",*q);
	For(i,1,*q) printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}