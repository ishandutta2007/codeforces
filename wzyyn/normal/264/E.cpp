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
const int N=250000;
int pos[N],val[N];
int n,Q,top;
pii q[N];
set<int> S;
struct TR11{
	int t[N*4],nn;
	void init(int n){
		for (nn=1;nn<=n+1;nn<<=1);
		For(i,1,2*nn-1) t[i]=-(1<<30);
	}
	void change(int p,int v){
		p+=nn; t[p]=v;
		for (p>>=1;p;p>>=1)
			t[p]=max(t[p<<1],t[p<<1|1]); 
	}
	int ask(int l,int r){
		int ans=-(1<<30);
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,t[l^1]);
			if (r&1)	ans=max(ans,t[r^1]);
		}
		return ans;
	}
}T1,T2;
void erase(pii v){
	T1.change(v.fi,-(1<<30));
	T2.change(v.se,-(1<<30)); 
	S.erase(v.se);
	pos[v.fi]=0;
	val[v.se]=0;
}
void insert_1(pii v){
	int f=T1.ask(v.fi+1,N);
	T1.change(v.fi,f+1);
	T2.change(v.se,f+1);
	S.insert(v.se);
	pos[v.fi]=v.se;
	val[v.se]=v.fi;
}
void insert_2(pii v){
	int f=T2.ask(v.se+1,N);
	//cout<<"INSERT "<<v.fi<<' '<<v.se<<' '<<f<<endl;
	T1.change(v.fi,f+1);
	T2.change(v.se,f+1);
	S.insert(v.se);
	pos[v.fi]=v.se;
	val[v.se]=v.fi;
}
pii find(){
	assert(S.size());
	int x=*S.begin();
	return pii(val[x],x);
}
int main(){
	scanf("%d%d",&n,&Q);
	T1.init(N); T1.change(N,0);
	T2.init(N); T2.change(N,0);
	For(i,1,Q){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1) scanf("%d",&y);
		if (tp==1){
			y+=Q-i;
			For(v,max(1,y-10),y-1) if (pos[v])
				q[++top]=pii(v,pos[v]);
			For(i,1,top) erase(q[i]);
			insert_2(pii(y,x));
			for (;top;insert_2(q[top--])); 
		}
		else{
			for (;top<x;){
				q[++top]=find();
				erase(q[top]);
			}
			--top;
			for (;top;insert_1(q[top--]));
		}
		printf("%d\n",T1.t[1]);
	}
}