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

const int N=100005;
int st[1<<15|5];
pii Read(){
	int x,y;
	scanf("%d%d",&x,&y);
	return pii(x,y);
}
int n,top,op_top;
int fa[N*5],S[N*5];
vector<int> e[N*5];
pii p1[N],p2[N];
pii q[N*5];
int op[N*10],q1[N*5];
pii LCA(pii x,pii y){
	pii z(0,0);
	Rep(i,29,0)
		if (x.fi&y.fi&(1<<i)){
			z.fi+=1<<i;
			y.fi-=1<<i;
			x.fi-=1<<i;
		}
		else if (x.se&y.se&(1<<i)){
			z.se+=1<<i;
			y.se-=1<<i;
			x.se-=1<<i;
		}
		else{
			if (x.fi&(1<<i)) x.fi=(1<<i)-1,x.se=0;
			if (x.se&(1<<i)) x.se=(1<<i)-1,x.fi=0;
			if (y.fi&(1<<i)) y.fi=(1<<i)-1,y.se=0;
			if (y.se&(1<<i)) y.se=(1<<i)-1,y.fi=0;
		}
	return z;
}
pii Fa(pii x){
	if (x.fi>=0&&((x.fi-1)&x.se)==0)
		return pii(x.fi-1,x.se);
	return pii(x.fi,x.se-1);
}
bool isFa(pii x,pii y){
	return LCA(x,y)==x;
}
bool cmp(pii x,pii y){
	if (x==y) return 0;
	int v=(x.fi^y.fi)|(x.se^y.se);
	int i=(v>>15?st[v>>15]+15:st[v]);
	int c0=(x.fi>>i)&1;
	int c1=(x.se>>i)&1;
	int c2=(y.fi>>i)&1;
	int c3=(y.se>>i)&1;
	int t1=(c0?0:(c1?2:1));
	int t2=(c2?0:(c3?2:1));
	if (t1!=t2){
		if (t1==2) return 0;
		if (t2==2) return 1;
		if (t1==1) return ((x.se&((1<<i)-1))==0)?1:0;
		if (t2==1) return ((y.se&((1<<i)-1))==0)?0:1;
	}
}
//L<C C<R
int Idx(pii x){
	return lower_bound(q+1,q+top+1,x,cmp)-q;
}

void dfs(int x){
	for (auto i:e[x])
		dfs(i),S[x]+=S[i];
	//cout<<x<<' '<<S[x]<<endl;
	if (S[x]){
		op[++op_top]=(x==1?0:q[fa[x]].fi+q[fa[x]].se+1);
		op[++op_top]=q[x].fi+q[x].se+1;
	}
}
int main(){
	For(i,0,32767) For(j,0,14)
		if (i&(1<<j)) st[i]=j;
	scanf("%d",&n);
	For(i,1,n){		
		p1[i]=Read();
		p2[i]=Read();
		q[++top]=p1[i];
		q[++top]=p2[i];
	}
	sort(q+1,q+top+1,cmp);
	For(i,1,top-1) q[top+i]=LCA(q[i],q[i+1]);
	top=top*2-1;
	For(i,1,n){
		pii L=LCA(p1[i],p2[i]);
		if (L!=pii(0,0)) q[++top]=Fa(L);
	}
	sort(q+1,q+top+1,cmp);
	top=unique(q+1,q+top+1)-q-1;
	int t=1; q1[1]=1;
	For(i,2,top){
		for (;top&&!isFa(q[q1[t]],q[i]);--t);
		fa[i]=q1[t];
		e[q1[t]].PB(i);
		q1[++t]=i;
	}
	For(i,1,n){
		++S[Idx(p1[i])];
		++S[Idx(p2[i])];
		assert(p1[i]==q[Idx(p1[i])]);
		assert(p2[i]==q[Idx(p2[i])]);
		//cout<<Idx(p1[i])<<' '<<Idx(p2[i])<<endl;
		pii L=LCA(p1[i],p2[i]);
		//cout<<L.fi<<' '<<L.se<<endl;
		--S[Idx(L)];
		if (L!=pii(0,0))
			--S[Idx(Fa(L))];
	}
	dfs(1);
	int ans=0;
	sort(op+1,op+op_top+1);
	t=1;
	For(i,2,op_top)
		if (t&&op[i]==op[t]) --t;
		else op[++t]=op[i];
	//For(i,1,t) cout<<op[i]<<' '; cout<<endl;
	cout<<t-(t&&op[1]==0)<<endl;
}