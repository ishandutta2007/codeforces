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
const int N=10005;
int a[N],b[N],p[N],q[N],pos[N];
int n,m,S;
void work(int x,int y){
	for (;;){
		int z=pos[q[x]^b[x]];
		if (z==x) return;
		if (z==y){
			swap(p[x],p[y]);
			swap(pos[p[x]],pos[p[y]]);
			return;
		}
		swap(q[y],q[z]);
		swap(p[x],p[y]);
		swap(pos[p[x]],pos[p[y]]);
		swap(p[x],p[z]);
		swap(pos[p[x]],pos[p[z]]);
		x=z;
	}
}
int main(){
	scanf("%d",&n);
	m=(1<<n)-1;
	For(i,0,m) scanf("%d",&a[i]),S^=a[i];
	if (S) return puts("Fou"),0;
	For(i,0,m) p[i]=q[i]=pos[i]=i;
	For(i,0,m-1){
		b[i+1]=b[i]^a[i]; b[i]=a[i];
		work(i,i+1);
	}
	puts("Shi");
	For(i,0,m) printf("%d ",p[i]);
	puts("");
	For(i,0,m) printf("%d ",q[i]);
}