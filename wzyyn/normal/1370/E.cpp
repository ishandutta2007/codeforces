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
const int N=1000005;
int n;
char s[N],t[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int mn=0,mx=0,v=0;
	For(i,1,n){
		v+=s[i]-'0';
		v-=t[i]-'0';
		mn=min(mn,v);
		mx=max(mx,v);
	}
	if (v) puts("-1");
	else printf("%d\n",mx-mn);
}