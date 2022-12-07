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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=100005;
int n;
ll a[N],b[N];
int f[N][2];
ll WIN(ll x,ll y){
	assert(x<=y);
	if (y&1) return !(x&1);
	if (x*2>y) return x&1;
	if (x*4>y) return 1;
	return WIN(x,y/4);
}
ll LOSE(ll x,ll y){
	assert(x<=y);
	if (x*2>y) return 1;
	return WIN(x,y/2);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&a[i],&b[i]);
	f[n][0]=WIN(a[n],b[n]);
	f[n][1]=LOSE(a[n],b[n]);
	//cout<<f[n][0]<<' '<<f[n][1]<<endl;
	Rep(i,n-1,1){
		if (f[i+1][0]==0&&WIN(a[i],b[i]))  f[i][0]=1;
		if (f[i+1][0]==1&&LOSE(a[i],b[i])) f[i][0]=1;
		if (f[i+1][1]==0&&WIN(a[i],b[i]))  f[i][1]=1;
		if (f[i+1][1]==1&&LOSE(a[i],b[i])) f[i][1]=1;
	}
	cout<<f[1][0]<<' '<<f[1][1]<<endl;
}
/*
eisi
ei
	si*2>ei,si
	si*4>ei,
	ei/4
*/