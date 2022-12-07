#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=200005;

int n,p;
int a[N],dl[N],dr[N];
int fa[N],id[N];

int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int qx[30],qy[30];
void getL(int *d){
	int t=0;
	for (int i=1;i<=n;i++){
		qx[++t]=a[i];
		qy[t]=i;
		for (int j=t-1;j;j--)
			qx[j]=gcd(qx[j+1],qx[j]);
		int nt=1;
		for (int j=2;j<=t;j++)
			if (qx[j]!=qx[j-1]){
				qx[++nt]=qx[j];
				qy[nt]=qy[j];
			}
		t=nt;
		d[i]=i-qy[t];
	}
} 
void solve(){
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	getL(dl);
	reverse(a+1,a+n+1);
	getL(dr);
	reverse(a+1,a+n+1);
	reverse(dr+1,dr+n+1);
	
	for (int i=1;i<=n;i++)
		fa[i]=i,id[i]=i;
	sort(id+1,id+n+1,cmp);
	long long ans=0;
	for (int i=1;i<=n;i++)
		if (a[id[i]]<=p){
			//cout<<id[i]<<' '<<dl[id[i]]<<' '<<dr[id[i]]<<endl;
			for (int x=id[i],j=dl[x];j;--j,--x)
				if (get(x)!=get(x-1))
					fa[get(x)]=get(x-1),ans+=a[id[i]];
				else break;
			for (int x=id[i],j=dr[x];j;--j,++x)
				if (get(x)!=get(x+1))
					fa[get(x)]=get(x+1),ans+=a[id[i]];
				else break;
		}
	for (int i=2;i<=n;i++)
		if (get(i)!=get(i-1))
			ans+=p;
	cout<<ans<<endl; 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}