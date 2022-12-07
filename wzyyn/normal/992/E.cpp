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
const int N=200005;
int n,Q,a[N],be[N];
int q[35][3],pos[35];
set<int> S[35];
ll t[N],sum[35][3];
int find_be(int x){
	int s=0;
	for (;(1<<s)<=x;s++);
	return s;
}
void change(int k,int v){
	for (;k<=n;k+=k&(-k)) t[k]+=v;
}
ll ask(int k){
	ll s=0;
	for (;k;k-=k&(-k)) s+=t[k];
	return s; 
}
void erase(int x){
	change(x,-a[x]);
	For(i,0,30) For(j,1,pos[i])
		if (q[i][j]>x) sum[i][j]-=a[x];
	int B=be[x];
	for (;pos[B];S[B].insert(q[B][pos[B]--]));
	S[B].erase(x);
	for (;pos[B]<2&&S[B].begin()!=S[B].end();){
		q[B][++pos[B]]=*S[B].begin();
		S[B].erase(S[B].begin());
		sum[B][pos[B]]=ask(q[B][pos[B]]-1);
	}
}
void insert(int x){
	change(x,a[x]);
	For(i,0,30) For(j,1,pos[i])
		if (q[i][j]>x) sum[i][j]+=a[x];
	int B=be[x]=find_be(a[x]);
	for (;pos[B];S[B].insert(q[B][pos[B]--]));
	S[B].insert(x);
	for (;pos[B]<2&&S[B].begin()!=S[B].end();){
		q[B][++pos[B]]=*S[B].begin();
		S[B].erase(S[B].begin());
		sum[B][pos[B]]=ask(q[B][pos[B]]-1);
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) change(i,a[i]);
	For(i,1,n){
		int B=be[i]=find_be(a[i]);
		if (pos[B]<2) q[B][++pos[B]]=i;
		else S[B].insert(i);
	}
	For(i,0,30) For(j,1,pos[i])
		sum[i][j]=ask(q[i][j]-1);
	while (Q--){
		int x;
		scanf("%d",&x);
		erase(x);
		scanf("%d",&a[x]);
		insert(x);
		int ans=-1;
		For(i,0,30) For(j,1,pos[i])
			if (sum[i][j]==a[q[i][j]])
				ans=q[i][j];//,cout<<q[i][j]<<' '<<a[q[i][j]]<<' '<<sum[i][j]<<endl;
		printf("%d\n",ans);
	}
}