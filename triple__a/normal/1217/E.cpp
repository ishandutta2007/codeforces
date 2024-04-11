#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
const int INF=1e9;

int tree[maxn<<2][9][2];
int n,m;

void pushup(int num){
	for (int i=0;i<9;++i){
		int j=0,k=0;
		while (j+k<2){
			if (tree[num<<1][i][j]<tree[num<<1|1][i][k]){
				tree[num][i][j+k]=tree[num<<1][i][j];
				j++;
			}
			else{
				tree[num][i][j+k]=tree[num<<1|1][i][k];
				k++;
			}
		}
	}
}

void build(int num,int l,int r){
	if (l==r){
		int u,v;
		cin>>u;
		v=u;
		for (int i=0;i<9;++i){
			if (v%10){
				tree[num][i][0]=u;
			}
			else{
				tree[num][i][0]=INF;
			}
			tree[num][i][1]=INF;
			v/=10;
		}
		return;
	}
	int md=(l+r)>>1;
	build(num<<1,l,md);
	build(num<<1|1,md+1,r);
	pushup(num);
}

void update(int num,int l,int r,int i,int x){
	if (l==r){
		int v=x;
		for (int i=0;i<9;++i){
			if (v%10){
				tree[num][i][0]=x;
			}
			else{
				tree[num][i][0]=INF;
			}
			tree[num][i][1]=INF;
			v/=10;
		}
		return;
	}
	int md=(l+r)>>1;
	if (i<=md) update(num<<1,l,md,i,x);
	if (i>md) update(num<<1|1,md+1,r,i,x);
	pushup(num);
}

void query(int num,int l,int r,int L,int R,int u[],int v[]){
	if (L<=l&&r<=R){
		for (int i=0;i<9;++i){
			u[i]=tree[num][i][0];
			v[i]=tree[num][i][1];
		}
		return;
	}
	int md=(l+r)>>1;
	int tu[9],tv[9],w[9],z[9];
	for (int i=0;i<9;++i){
		tu[i]=tv[i]=w[i]=z[i]=INF;
	}
	if (L<=md) query(num<<1,l,md,L,R,tu,tv);
	if (R>md) query(num<<1|1,md+1,r,L,R,w,z);
	for (int i=0;i<9;++i){
		if (tu[i]<w[i]){
			if (tv[i]<w[i]){
				u[i]=tu[i],v[i]=tv[i];
			}
			else{
				u[i]=tu[i],v[i]=w[i];
			}
		}
		else{
			if (tu[i]<z[i]){
				u[i]=w[i],v[i]=tu[i];
			}
			else{
				u[i]=w[i],v[i]=z[i];
			}
		}
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	build(1,1,n);
	while(m--){
		int op,u,v;
		cin>>op>>u>>v;
		if (op==1){
			update(1,1,n,u,v);
		}
		else{
			int t1[9],t2[9];
			query(1,1,n,u,v,t1,t2);
			int ans=2*INF;
			for (int i=0;i<9;++i){
				if (t2[i]==INF) continue;
				ans=min(ans,t1[i]+t2[i]);
			}
			if (ans!=2*INF){
				cout<<ans<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
	}
}