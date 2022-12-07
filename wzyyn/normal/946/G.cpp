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
const int N=400005;
int n,a[N],q[N];
struct Tree{
	int t[N];
	void change(int x,int v){
		for (;x<=*q;x+=x&(-x)) t[x]=max(t[x],v);
	}
	int ask(int x){
		int s=0;
		for (;x;x-=x&(-x)) s=max(s,t[x]);
		return s;
	}
}T1,T2;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		q[++*q]=a[i]-i;
		q[++*q]=a[i]-i+1;
	}
	sort(q+1,q+*q+1);
	int pr=0,pp=1,ans=0;
	For(i,1,n){
		int p1=lower_bound(q+1,q+*q+1,a[i]-i)-q;
		int p2=lower_bound(q+1,q+*q+1,a[i]-i+1)-q;
		int v1=T1.ask(p1)+1;
		int v2=T2.ask(p2)+1;
		ans=max(ans,max(v1,v2));
		T1.change(p1,v1);
		T2.change(pp,pr);
		T2.change(p2,v2);
		pp=p1; pr=v1;
	}
	cout<<n-1-min(ans,n-1)<<endl;
}