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
const int N=5050000;
const int M=200005;
int tr[N],cnt[N],f[N][9];
int n,Q,a[M],ans[M*6],val[15];
vector<int> di[N];
vector<pii> vec[M];
void init(){
	For(i,1,N-1) For(j,1,(N-1)/i/i) tr[i*i*j]=j;
	//cout<<tr[8]<<endl;
	//cout<<clock()<<endl;
	For(i,1,N-1) if (tr[i]==i)
		For(j,1,(N-1)/i) if (tr[i*j]==i*j)
			di[i*j].PB(i);
	//cout<<clock()<<endl;
	For(i,2,N-1) if (!cnt[i])
		For(j,1,(N-1)/i) ++cnt[i*j];
	//cout<<cnt[2*3*5*7]<<endl;
	//cout<<clock()<<endl;
}
int main(){
	//freopen("1.in","r",stdin);
	init();
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]),a[i]=tr[a[i]];
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[y].PB(pii(x,i));
		ans[i]=1<<30;
	}
	For(i,1,n){
		for (auto j:di[a[i]]) For(k,0,8)
			val[k+cnt[j]]=max(val[k+cnt[j]],f[a[i]/j][k]);
		for (auto j:vec[i]) For(k,0,16)
			if (j.fi<=val[k]) ans[j.se]=min(ans[j.se],k);
		for (auto j:di[a[i]])
			f[a[i]/j][cnt[j]]=max(f[a[i]/j][cnt[j]],i);
	}
	For(i,1,Q) printf("%d\n",ans[i]);
}
/*

*/