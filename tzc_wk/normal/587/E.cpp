/*

  0. Enough array size? Enough array size? Enough array size? Interger overflow?

  1. Think TWICE, Code ONCE!

  Are there any counterexamples to your algo?

  2. Be careful about the BOUNDARIES!

  N=1? P=1? Something about 0?

  3. Do not make STUPID MISTAKES!

  Time complexity? Memory usage? Precision error?

*/

#include <bits/stdc++.h>

using namespace std;

#define fi first

#define se second

#define fz(i,a,b) for(int i=a;i<=b;i++)

#define fd(i,a,b) for(int i=a;i>=b;i--)

#define ffe(it,v) for(__typeof it=v.begin();it!=v.end();it++)

#define fill0(a) memset(a,0,sizeof(a))

#define fill1(a) memset(a,-1,sizeof(a))

#define fillbig(a) memset(a,63,sizeof(a))

#define pb push_back

#define mp make_pair

typedef pair<int,int> pii;

typedef long long ll;

int n,m;

struct linear{

	int b[32],siz;

	void clear(){memset(b,0,sizeof(b));siz=0;}//clear the linear base

	void ins(int v){//insert number v

		for(int i=30;~i;i--) if(v>>i&1){

			if(!b[i]){b[i]=v;siz++;return;}

			v^=b[i];

		}

	}

	friend linear operator +(linear x,linear y){//merge two linears

		linear ans;ans.clear();

		for(int i=0;i<31;i++) if(x.b[i]) ans.ins(x.b[i]);

		for(int i=0;i<31;i++) if(y.b[i]) ans.ins(y.b[i]);

		return ans;

	}

};

int bit[200005];

inline void add(int x,int v){for(int i=x;i<=n;i+=(i&(-i))) bit[i]^=v;}

inline int get(int x){int sum=0;for(int i=x;i;i-=(i&(-i))) sum^=bit[i];return sum;}

int a[200005],blk;

const int SIZ=622;

int L[3005],R[3005],bel[200005];

linear f[3005];

inline void modify(int v,int x){

	f[bel[v]].clear();add(v,a[v]);a[v]^=x;add(v,a[v]);

	for(int i=L[bel[v]];i<=R[bel[v]];i++){

		f[bel[v]].ins(a[i]);

	}

}

inline linear query(int l,int r){

//	printf("%d %d\n",l,r);

	linear ans;ans.clear();

	ans.ins(get(l-1));

	if(l>r) return ans;

	if(bel[l]==bel[r]){

		for(int i=l;i<=r;i++) ans.ins(a[i]);

	}

	else{

		for(int i=l;i<=R[bel[l]];i++) ans.ins(a[i]);

		for(int i=L[bel[r]];i<=r;i++) ans.ins(a[i]);

		for(int i=bel[l]+1;i<bel[r];i++) ans=ans+f[i];

	}

	return ans;

}

int main(){

	scanf("%d%d",&n,&m);

	blk=(n-1)/SIZ+1;

	for(int i=1;i<=blk;i++){

		f[i].clear();

		L[i]=(i-1)*SIZ+1;
		R[i]=min(i*SIZ,n);
		for(int j=L[i];j<=R[i];j++){
			bel[j]=i;
		}
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i;i--) a[i]^=a[i-1],f[bel[i]].ins(a[i]);
	for(int i=1;i<=n;i++) add(i,a[i]);
	while(m--){
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			int x;scanf("%d",&x);modify(l,x);
			if(r!=n) modify(r+1,x);
		}
		else{
			printf("%d\n",1ll<<(query(l+1,r).siz));
		}
	}
	return 0;
}