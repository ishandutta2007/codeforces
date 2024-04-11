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
char a[N];
int type,n;
void query(int k,int *x,int *y,int *z){
	if (!k) return;
	if (type==0){
		printf("Q %d ",k);
		For(i,1,k) printf(" %d %d ",x[i],y[i]);
		puts("");
		fflush(stdout);
		scanf("%s",a+1);
		For(i,1,k) z[i]=(a[i]=='1');
	}
	else{
		For(i,1,k)
			z[i]=(a[x[i]]==a[y[i]]);
	}
}
void init(){
	if (!type){
		scanf("%d",&n);
	}
	else{
		n=1000;
		srand(rand());
		For(i,1,n) a[i]=rand()%3+1;
	}
}
int x[N],y[N],v[N],spe[N],q[N];
int ans[5][N],co[N];
void solve(){
	int cnt=*q=0;
	For(i,1,n) spe[i]=0;
	for (int i=2;i<=n;i+=2) x[++cnt]=i,y[cnt]=i-1;
	query(cnt,x,y,v);
	For(i,1,cnt) spe[x[i]]=v[i];
	cnt=0;
	for (int i=3;i<=n;i+=2) x[++cnt]=i,y[cnt]=i-1;
	query(cnt,x,y,v);
	For(i,1,cnt) spe[x[i]]=v[i];
	For(i,1,n) if (!spe[i]) q[++*q]=i;
	For(i,1,n) spe[i]=0;
	cnt=0;
	for (int i=3;i<=*q;i+=4) x[++cnt]=q[i],y[cnt]=q[i-2];
	for (int i=4;i<=*q;i+=4) x[++cnt]=q[i],y[cnt]=q[i-2];
	query(cnt,x,y,v);
	For(i,1,cnt) spe[x[i]]=v[i];
	cnt=0;
	for (int i=5;i<=*q;i+=4) x[++cnt]=q[i],y[cnt]=q[i-2];
	for (int i=6;i<=*q;i+=4) x[++cnt]=q[i],y[cnt]=q[i-2];
	query(cnt,x,y,v);
	For(i,1,cnt) spe[x[i]]=v[i];
	co[1]=1; co[2]=2;
	For(i,3,*q) co[i]=(spe[q[i]]?co[i-2]:6-co[i-1]-co[i-2]);
	q[(*q)+1]=n+1;
	*ans[1]=*ans[2]=*ans[3]=0;
	For(i,1,*q) For(j,q[i],q[i+1]-1)
		ans[co[i]][++*ans[co[i]]]=j;
	if (type==0){
		printf("A %d %d %d\n",*ans[1],*ans[2],*ans[3]);
		For(i,1,*ans[1]) printf("%d ",ans[1][i]); puts("");
		For(i,1,*ans[2]) printf("%d ",ans[2][i]); puts("");
		For(i,1,*ans[3]) printf("%d ",ans[3][i]); puts("");
		fflush(stdout);
	}
	else{
		if (*ans[1]&&*ans[2]) assert(a[ans[1][1]]!=a[ans[2][1]]);
		if (*ans[1]&&*ans[3]) assert(a[ans[1][1]]!=a[ans[3][1]]);
		if (*ans[2]&&*ans[3]) assert(a[ans[2][1]]!=a[ans[3][1]]);
		For(i,2,*ans[1]) assert(a[ans[1][i]]==a[ans[1][i-1]]);
		For(i,2,*ans[2]) assert(a[ans[2][i]]==a[ans[2][i-1]]);
		For(i,2,*ans[3]) assert(a[ans[3][i]]==a[ans[3][i-1]]);
	}
}
int main(){
	int T=5;
	scanf("%d",&T);
	while (T--){
		type=0;
		init();
		solve();
	}
}