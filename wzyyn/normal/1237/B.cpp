#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n,ans;
int a[N],p[N],t[N];
void change(int k,int v){
	for (;k<=n;k+=k&(-k)) t[k]+=v;
}
int ask(int k){
	int ans=0;
	for (;k;k-=k&(-k)) ans+=t[k];
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	For(i,1,n)
		change(a[i],1);
	For(i,1,n){
		scanf("%d",&a[i]);
		if (ask(p[a[i]])>1) ++ans;
		change(p[a[i]],-1);
	}
	printf("%d\n",ans);
}