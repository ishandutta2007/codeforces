#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
int n,a[N],f[N],atg,mx;
void insert(int c,int v){
	v-=atg;
	f[c]=max(f[c],v);
	mx=max(mx,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,0,n) f[i]=-(1<<29);
	mx=-(1<<29);
	insert(0,0);
	For(i,2,n){
		int nv=max(mx,f[a[i]]+1)+atg;
		if (a[i]==a[i-1]) ++atg;
		insert(a[i-1],nv);
	}
	int v=-(1<<30);
	For(i,0,n) v=max(v,f[i]);
	cout<<n-(v+atg)<<endl;
}
/*
*/