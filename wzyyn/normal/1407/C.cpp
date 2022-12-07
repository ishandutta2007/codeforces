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
int n,a[10005];
int query(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>x;
	return x;
}
int main(){
	scanf("%d",&n);
	int p=1;
	For(i,2,n){
		int v1=query(i,p);
		int v2=query(p,i);
		if (v1<v2) a[p]=v2,p=i;
		else a[i]=v1;
	}
	a[p]=n;
	printf("!");
	For(i,1,n) printf(" %d",a[i]);
	puts("");
}