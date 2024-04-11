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
const int N=505;
struct node{
	pii p1,p2;
	int id;
};
vector<node> vec[N*4];
char s[N][N];
int n,m,Q,R[N],ans[600005];
bitset<N> B[N][N],emp;
void insert(int k,int l,int r,pii p1,pii p2,int id){
	int mid=(l+r)/2;
	if (l==r||(p1.fi<=mid&&p2.fi>mid))
		return vec[k].PB((node){p1,p2,id}),void(0);
	if (p2.fi<=mid) insert(k*2,l,mid,p1,p2,id);
	if (p1.fi>mid) insert(k*2+1,mid+1,r,p1,p2,id);
}
void solve(int k,int l,int r){
	if (l==r){
		For(i,1,m)
			if (s[l][i]=='#') R[i]=i;
			else R[i]=R[i-1];
		for (auto i:vec[k])
			if (R[i.p2.se]<i.p1.se)
				ans[i.id]=1;
		return;
	}
	int mid=(l+r)/2;
	solve(k*2,l,mid);
	solve(k*2+1,mid+1,r);
	For(i,1,m) emp[i]=0;
	For(i,l,r) For(j,1,m) B[i][j]=emp;
	For(i,mid,mid+1) For(j,1,m)
		if (s[i][j]=='.') B[i][j][j]=1;
	Rep(i,mid,l) Rep(j,m,1) if (s[i][j]=='.'){
		if (i!=mid&&s[i+1][j]=='.') B[i][j]|=B[i+1][j];
		if (j!=m&&s[i][j+1]=='.') B[i][j]|=B[i][j+1];
	}
	For(i,mid+1,r) For(j,1,m) if (s[i][j]=='.'){
		if (i!=mid+1&&s[i-1][j]=='.') B[i][j]|=B[i-1][j];
		if (j!=1&&s[i][j-1]=='.') B[i][j]|=B[i][j-1];
	}
	for (auto i:vec[k])
		if ((B[i.p1.fi][i.p1.se]&B[i.p2.fi][i.p2.se]).count())
			ans[i.id]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	scanf("%d",&Q);
	For(i,1,Q){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		insert(1,1,n,pii(x1,y1),pii(x2,y2),i);
	}
	solve(1,1,n);
	For(i,1,Q) puts(ans[i]?"Yes":"No");
}