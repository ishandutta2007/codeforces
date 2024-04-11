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
const int N=200005;
char s[N],ns[N];
int n,t[N],mat[N];
vector<int> v1[N];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
int main(){
	scanf("%d%s",&n,s+1);
	//n=strlen(s+1);
	memcpy(ns,s,sizeof(ns));
	reverse(ns+1,ns+n+1);
	For(i,1,n) v1[s[i]].PB(i);
	Rep(i,n,1){
		mat[i]=v1[ns[i]].back();
		v1[ns[i]].pop_back();
	}
	ll ans=0;
	For(i,1,n){
		change(mat[i],1);
		ans+=i-ask(mat[i]);
	}
	cout<<ans<<endl;
}