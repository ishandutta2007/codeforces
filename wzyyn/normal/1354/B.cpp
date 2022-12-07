#include<bits/stdc++.h>
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
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
char s[200005];
int la[5];
void solve(){
	scanf("%s",s+1);
	int v=1<<30;
	int n=strlen(s+1);
	For(i,0,2) la[i]=-(1<<30);
	For(i,1,n){
		la[s[i]-'1']=i;
		int vv=min(min(la[0],la[1]),la[2]);
		v=min(v,i-vv+1);
	}
	if (v>2000000) printf("0\n");
	else printf("%d\n",v);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}