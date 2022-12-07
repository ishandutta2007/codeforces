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
const int N=100005;
int n,id[N],q[N*2],a[N],top;
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d",&n); top=n;
	For(i,1,n) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n) q[i]=id[i]*2;
	For(i,1,n-1) printf("%d %d\n",q[i],q[i+1]);
	For(i,1,n){
		int v=a[id[i]];
		printf("%d %d\n",q[i+v-1],id[i]*2-1);
		if (i+v>top) q[++top]=id[i]*2-1;
	}
}