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
int n,a[N],f[N],atg;
pii mn1,mn2;
void insert(int c,int v){
	v-=atg;
	f[c]=min(f[c],v);
	pii temp(f[c],c);
	if (temp<mn1) swap(mn1,temp);
	if (mn1.se!=temp.se&&temp<mn2) swap(mn2,temp);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,0,n) f[i]=1<<29;
	mn1=mn2=pii(1<<29,-1);
	insert(0,0);
	For(i,2,n){
		int nv;
		if (mn1.se==a[i])
			nv=min(mn1.fi+1,mn2.fi);
		else nv=mn1.fi;
		nv+=atg;
		if (a[i]==a[i-1]) ++atg;
		insert(a[i-1],nv);
	}
	int v=1<<30;
	For(i,0,n) v=min(v,f[i]);
	cout<<n-(v+atg)<<endl;
}
/*
*/