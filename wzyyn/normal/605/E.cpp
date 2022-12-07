#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=1005;
int n,tr[N][N];
int vis[N],q[N];
double val[N];
void update(int j){
	double p=1,v=1;
	For(i,1,*q){
		v+=p*tr[j][q[i]]*val[q[i]]/100.0;
		p*=(100-tr[j][q[i]])/100.0;
	}
	val[j]=(p<1-1e-9?v/(1-p):1e100);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n)
		scanf("%d",&tr[i][j]);
	q[++*q]=n; vis[n]=1;
	For(i,1,n-1) update(i);
	For(i,1,n-1){
		int id=-1;
		For(j,1,n-1)
			if (!vis[j]&&(id==-1||val[id]>val[j]))
				id=j;
		vis[id]=1; q[++*q]=id;
		For(j,1,n-1)
			if (!vis[j])
				update(j);
	}
	printf("%.10lf\n",val[1]);
}