#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
const int M=400005;
struct TARR{
	int a[N*2];
	void change(int x,int v){
		for (;x<N*2;x+=x&(-x)) a[x]+=v;
	}
	int ask(int x){
		int ans=0;
		for (;x;x-=x&(-x)) ans+=a[x];
		return ans;
	}
}T[5];
struct node{
	int tp,x,y,v,id;
}q[M],qq[M];
int n,Q,id,top;
int ans[M];
bool cmp(node x,node y){
	return x.x==y.x?x.tp<y.tp:x.x<y.x;
}
void CDQ(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	CDQ(l,mid);
	CDQ(mid+1,r);
	int p1=l,p2=mid+1,p3=l;
	for (;p1<=mid||p2<=r;)
		if (p2>r||(p1<=mid&&cmp(q[p1],q[p2])))
			qq[p3++]=q[p1++];
		else qq[p3++]=q[p2++];
	//assert(p1==mid+1);
	//assert(p2==r+1);
	//assert(p3==r+1);
	For(i,l,r) q[i]=qq[i];
	For(i,l,r)
		if (q[i].id<=mid&&q[i].tp<=3){
			if (q[i].tp==1) T[1].change(q[i].y,q[i].v);
			if (q[i].tp==2) T[2].change(q[i].y+q[i].x,q[i].v);
			if (q[i].tp==3) T[3].change(q[i].y-q[i].x+N,q[i].v);
		}
		else if (q[i].id>mid&&q[i].tp==4){
			ans[q[i].v]+=T[1].ask(q[i].y);
			ans[q[i].v]+=T[2].ask(q[i].y+q[i].x);
			ans[q[i].v]+=T[3].ask(q[i].y-q[i].x+N);
		}
	For(i,l,r)
		if (q[i].id<=mid&&q[i].tp<=3){
			if (q[i].tp==1) T[1].change(q[i].y,-q[i].v);
			if (q[i].tp==2) T[2].change(q[i].y+q[i].x,-q[i].v);
			if (q[i].tp==3) T[3].change(q[i].y-q[i].x+N,-q[i].v);
		}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,Q){
		int tp,x,y,d;
		scanf("%d",&tp);
		if (tp==2){
			scanf("%d%d",&x,&y);
			q[++top]=(node){4,x,y,++id};
		}
		else{
			scanf("%d%d%d%d",&tp,&x,&y,&d);
			if (tp==1){
				q[++top]=(node){1,x,y,1};
				q[++top]=(node){1,x+d+1,y,-1};
				q[++top]=(node){2,x,y+d+1,-1};
				q[++top]=(node){2,x+d+1,y,1};
			}
			if (tp==2){
				q[++top]=(node){1,x,y+1,-1};
				q[++top]=(node){1,x+d+1,y+1,1};
				q[++top]=(node){3,x,y-d,1};
				q[++top]=(node){3,x+d+1,y+1,-1};
			}
			if (tp==3){
				q[++top]=(node){1,x-d,y,1};
				q[++top]=(node){1,x+1,y,-1};
				q[++top]=(node){3,x-d,y+1,-1};
				q[++top]=(node){3,x+1,y+d+2,1};
			}
			if (tp==4){
				q[++top]=(node){1,x-d,y+1,-1};
				q[++top]=(node){1,x+1,y+1,1};
				q[++top]=(node){2,x-d,y,1};
				q[++top]=(node){2,x+1,y-d-1,-1};
			}
		}
	}
	For(i,1,top) q[i].id=i;
	//For(i,1,top) printf("%d %d %d %d\n",q[i].x,q[i].y,q[i].v,q[i].tp);
	CDQ(1,top);
	//For(i,1,top) printf("%d %d %d %d\n",q[i].x,q[i].y,q[i].v,q[i].tp);
	
	For(i,1,id)
		printf("%d\n",ans[i]);
}
/*
2:x+y
3:-x+y
*/