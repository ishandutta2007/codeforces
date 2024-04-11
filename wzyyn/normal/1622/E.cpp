#include<bits/stdc++.h>

using namespace std;

const int N=10005;
int n,m,tab[25],bic[N];
int a[15],msk[N],re[N];
int ans[N],co[N],id[N];
char s[N];
void init(){
	for (int i=1;i<N;i++)
		bic[i]=bic[i-(i&(-i))]+1;
}
bool cmp(int x,int y){
	return co[x]<co[y];
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) msk[i]=0;
	for (int i=0;i<n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			if (s[j]=='1') msk[j]|=1<<i;
	}
	int re=-1,mxv=-1;
	for (int i=0;i<1<<n;i++){
		int tmp=0,v=m;
		for (int j=0;j<n;j++) tmp+=(i&(1<<j)?a[j]:-a[j]);
		for (int j=1;j<=m;j++) ++tab[12+bic[msk[j]&(~i)]-bic[msk[j]&i]];
		for (int j=10;j>=-10;j--)
			for (;tab[j+12];--tab[j+12]) tmp+=j*v,--v;
		if (tmp>=re) re=tmp,mxv=i;
	}
	//cout<<re<<' '<<mxv<<endl;
	for (int i=1;i<=m;i++)
		co[i]=bic[msk[i]&(~mxv)]-bic[msk[i]&mxv],id[i]=i;
	sort(id+1,id+m+1,cmp);
	for (int i=1;i<=m;i++)
		ans[id[i]]=i;
	for (int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}