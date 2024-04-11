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
vector<int> v[100005];
int top,n;
void ADD(int x,int y,int z){
	++top;
	v[top].PB(x);
	v[top].PB(y);
	v[top].PB(z);
}
void ADD(int p,int x,int y,int z){
	++top;
	v[top].PB(p);
	v[top].PB(x);
	v[top].PB(y);
	v[top].PB(z);
}
void solve(int n){
	if (n==3){
		ADD(1,2,3);
		ADD(1,2,3);
		return;
	}
	if (n==4){
		ADD(1,2,3);
		ADD(1,2,4);
		ADD(1,3,4);
		ADD(2,3,4);
		return;
	}
	solve(n-2);
	int p=n-2;
	if (p&1){
		ADD(p,n-1,n);
		ADD(p,n-1,n);
		p-=1;
	}
	else{
		ADD(p,n-1,n);
		ADD(p-1,n-1,n);
		ADD(p,n-1,p-1,n);
		p-=2;
	}
	for (;p;p-=2){
		ADD(p,n-1,p-1,n);
		ADD(p,n-1,p-1,n);
	}
}
int main(){
	scanf("%d",&n);
	solve(n);
	printf("%d\n",top);
	For(i,1,top){
		printf("%d ",v[i].size());
		for (auto j:v[i])
			printf("%d ",j);
		puts("");
	}
}