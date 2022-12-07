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
const int N=100005;
int ch[N*12][4],nd=1,m;
char s[N];
ll T;
struct Mat{
	ll a[4][4];
	Mat(){
		memset(a,50,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,0,3) For(j,0,3) For(k,0,3)
			ans.a[i][j]=min(ans.a[i][j],a[i][k]+b.a[k][j]);
		return ans;
	}
}tr,bas,P[65];
void dfs(int x,int c1,int l){
	For(i,0,3)
		if (!ch[x][i])
			tr.a[c1][i]=min(tr.a[c1][i],1ll*l-1);
		else dfs(ch[x][i],l==1?i:c1,l+1);
}
int main(){
	scanf("%lld",&T);
	scanf("%s",s+1);
	m=strlen(s+1);
	For(i,1,m){
		int p=i,l=1,x=1;
		for (;l<=11&&p<=m;){
			int c=s[p]-'A';
			if (!ch[x][c]) ch[x][c]=++nd;
			x=ch[x][c]; ++l; ++p;
		}
	}
	memset(tr.a,50,sizeof(tr.a));
	dfs(1,-1,1);
	//For(i,0,3) For(j,0,3)
	//	cout<<i<<' '<<j<<' '<<tr.a[i][j]<<endl;
	P[0]=tr;
	For(i,1,60) P[i]=P[i-1]*P[i-1];
	For(i,0,3) bas.a[i][i]=0;
	ll ans=0;
	//cout<<bas.a[0][0]<<endl;
	Rep(i,60,0){
		Mat tmp=bas*P[i];
		bool flg=0;
		For(j,0,3) For(k,0,3)
			flg|=(tmp.a[j][k]<T);
		if (flg) bas=tmp,ans+=(1ll<<i);
	}
	printf("%lld\n",ans+1);
}