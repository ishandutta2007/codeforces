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
int n,q[N],id[N],sz[N],fa[N];
int Qsub(int be,int l,int r){
	printf("1\n1\n%d\n",r-l+1);
	For(i,l,r) printf("%d ",q[i]); puts("");
	printf("%d\n",be);
	fflush(stdout);
	scanf("%d",&be);
	return be;
}
void divide(int be,int l,int r){
	if (l>r||!Qsub(be,l,r)) return;
	if (l==r) return fa[q[l]]=be,void(0);
	int mid=(l+r)/2;
	divide(be,l,mid);
	divide(be,mid+1,r);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) q[i]=i,id[i]=i;
	For(i,1,n) sz[i]=Qsub(i,2,n)+(i==1);
	For(i,1,n) For(j,i+1,n)
		if (sz[id[i]]<sz[id[j]])
			swap(id[i],id[j]);
	Rep(i,n,1){
		divide(id[i],1,*q);
		int tmp=*q; *q=0;
		For(j,1,tmp) if (!fa[q[j]]) q[++*q]=q[j];
		q[++*q]=id[i];
	}
	puts("ANSWER");
	For(i,2,n) printf("%d %d\n",fa[i],i);
}