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
#define y1 fdhjksa
using namespace std;
const int N=100005;
int stk[N],q[N],que[N];
int fa[N],d[N],n,mx;
int spe[N];
vector<int> e[N];
void getans(int x){
	stk[++*stk]=x;
	q[++*q]=x;
	for (auto i:e[x])
		if (!spe[i]){
			for (;stk[*stk]!=x;){
				que[++*que]=i;
				--*stk;
			}
			getans(i);
		}
	for (auto i:e[x])
		if (spe[i]){
			for (;stk[*stk]!=x;){
				que[++*que]=i;
				--*stk;
			}
			getans(i);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		scanf("%d",&fa[i]);
		e[fa[i]].PB(i);
		d[i]=d[fa[i]]+1;
		if (d[i]>d[mx]) mx=i;
	}
	for (int x=mx;x;x=fa[x]) spe[x]=1;
	getans(0);
	For(i,1,n) printf("%d ",q[i]);
	puts("");
	printf("%d\n",*que);
	For(i,1,*que) printf("%d ",que[i]);
}