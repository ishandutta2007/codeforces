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
const int N=200005;
int a[N],n;
pii query(int l,int r){
	l=max(l,1);
	r=min(r,n);
	assert(l<=r);
	cout<<"? "<<l<<' '<<r<<endl;
	cin>>l;
	assert(l!=-1);
	cin>>r;
	return pii(l,r); 
}
int query2(int x){
	if (a[x]!=-1) return a[x]; 
	cout<<"? "<<x<<' '<<x<<endl;
	int y;
	cin>>x;
	assert(x!=-1);
	cin>>y;
	return x;
}
void divide(int l,int r){
	//cout<<"Q "<<l<<' '<<r<<endl;
	if (l>r) return;
	pii tmp=query(l,r);
	int k=0,q[5],pl=-1,pr=-1; q[0]=0;
	for (;1<<(k+1)<=tmp.se;k++);
	For(i,l,r) if (i%(1<<k)==0){
		a[i]=query2(i);
		if (a[i]==tmp.fi) q[++*q]=i;
	}
	if (*q==2){
		pl=q[1];
		pl-=query(pl-(1<<k)+1,pl+(1<<k)).se-(1<<k)-1;
		pr=pl+tmp.se-1;
	}
	else{
		pii v1=query(q[1]-(1<<k)+1,q[1]);
		pii v2=query(q[1],q[1]+(1<<k)-1);
		if (v1.fi==tmp.fi) pl=q[1]-v1.se+1,pr=pl+tmp.se-1;
		if (v2.fi==tmp.fi) pr=q[1]+v2.se-1,pl=pr-tmp.se+1;
	}
	For(i,pl,pr) a[i]=tmp.fi;
	divide(l,pl-1);
	divide(pr+1,r);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) a[i]=-1;
	divide(1,n);
	cout<<"! ";
	For(i,1,n) cout<<a[i]<<' ';
	cout<<endl;
}
/*
6
2 2
2 1
3 1
4 1
1 1
2 2
1 1
1 1
1 1
1 1
3 2

*/