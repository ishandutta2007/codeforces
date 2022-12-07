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
int a[N],b[N],top;
int T,n,G,v,ans[N];
map<int,int> mp;
pii q[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int x,int y,int &a,int &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}
int getinv(int x,int y){
	int a,b;
	exgcd(x,y,a,b);
	return (a%y+y)%y;
}
void solve(int l,int r){
	if (!v){
		For(i,l,r) ans[q[i].se]=1;
		return;
	}
	int iv=getinv(v/G,T/G);
	For(i,l,r) q[i].fi=1ll*iv*(b[q[i].se]/G)%(T/G);
	sort(q+l,q+r+1);
	For(i,l,r-1) ans[q[i].se]=q[i+1].fi-q[i].fi;
	ans[q[r].se]=T/G+q[l].fi-q[r].fi;
}
int main(){
	scanf("%d%d",&T,&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) b[i]=(b[i-1]+a[i])%T;
	v=(a[1]+b[n])%T; G=gcd(v,T);
	//cout<<v<<' '<<T<<' '<<G<<endl;
	For(i,1,n){
		if (!mp[b[i]])
			q[++top]=pii(b[i]%G,i);
		mp[b[i]]=1;
	}
	sort(q+1,q+top+1);
	int l=1;
	For(i,2,n+1)
		if (i==n+1||q[i].fi!=q[i-1].fi)
			solve(l,i-1),l=i;
	For(i,1,n) printf("%d ",ans[i]);
}
/*
15 25
5 4 3 6 9 9 4 9 10 9 6 7 9 8 9 3 6 1 3 9 2 4 1 8 3
*/