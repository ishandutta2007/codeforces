#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int ans1,ans2;
struct tree{
	int t1[N*4],t2[N*4];
	tree(){
		memset(t1,63,sizeof(t1));
		memset(t2,63,sizeof(t2));
	}
	void update(int &v1,int &v2,int v3,int v4){
		if (v3<v1) swap(v3,v1);
		if (v3<v2) swap(v3,v2);
		if (v4<v1) swap(v4,v1);
		if (v4<v2) swap(v4,v2);
	}
	void pushup(int k){
		t1[k]=t1[k*2]; t2[k]=t2[k*2];
		update(t1[k],t2[k],t1[k*2+1],t2[k*2+1]);
	}
	void change(int k,int l,int r,int p,int v){
		if (l==r){
			t1[k]=v;
			return;
		}
		int mid=(l+r)/2;
		if (p<=mid) change(k*2,l,mid,p,v);
		else change(k*2+1,mid+1,r,p,v);
		pushup(k);
	}
	void ask(int k,int l,int r,int x,int y){
		if (l==x&&r==y){
			update(ans1,ans2,t1[k],t2[k]);
			return;
		}
		int mid=(l+r)/2;
		if (y<=mid) ask(k*2,l,mid,x,y);
		else if (x>mid) ask(k*2+1,mid+1,r,x,y);
		else{
			ask(k*2,l,mid,x,mid);
			ask(k*2+1,mid+1,r,mid+1,y);
		}
	}
}T[10];
int n,Q;
void add(int x,int v){
	int tmp=v;
	For(i,1,9){
		int val=v%10; v/=10;
		T[i].change(1,1,n,x,val?tmp:(1<<30)-1);
	}
}
int ask(int l,int r){
	int ans=2147480000;
	For(i,1,9){
		ans1=ans2=(1<<30)-1;
		T[i].ask(1,1,n,l,r);
		if (ans1<=1000000000&&ans2<=1000000000)
			ans=min(ans,ans1+ans2);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		add(i,x);
	}
	//while(1);
	For(i,1,Q){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1) add(l,r);
		else{
			int ans=ask(l,r);
			if (ans>2000000000) puts("-1");
			else printf("%d\n",ans);
		}
	}
}