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

int n1,n2,n3;
pll read(int n){
	ll v1=0,v2=1<<30,x=0;
	for (;n--;){
		scanf("%lld",&x);
		v1+=x; v2=min(v2,x);
	}
	return pll(v1,v2);
}
int main(){
	scanf("%d%d%d",&n1,&n2,&n3);
	pll v1=read(n1);
	pll v2=read(n2);
	pll v3=read(n3);
	ll res=v1.fi+v2.fi+v3.fi-2*(v1.se+v2.se+v3.se)+2*max(v1.se,max(v2.se,v3.se));
	res=max(res,v1.fi+v2.fi-v3.fi);
	res=max(res,v1.fi+v3.fi-v2.fi);
	res=max(res,v3.fi+v2.fi-v1.fi);
	cout<<res<<endl;
}
/*
A
B
C

A-B1-C/A
A-C1-B

A-C1-B/A
A-C1-A1-B1-C1
*/