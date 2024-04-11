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
const int M=505;
int f[N][26],n;
int app[N],L,R,k;
int vl[M],vr[M],c[M];
int pl[M],pr[M];
char s[N];
ll ans,res;
void add(int x,int v){
	res-=(L<=app[x]&&app[x]<=R);
	app[x]+=v;
	res+=(L<=app[x]&&app[x]<=R);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) For(j,0,25)
		f[i][j]=f[i-1][j]+(s[i]==j+'a');
	scanf("%d%d%d",&k,&L,&R);
	For(i,1,k){
		scanf("%s%d%d",s,&vl[i],&vr[i]);
		pl[i]=0; pr[i]=0;
		c[i]=s[0]-'a';
	}
	For(i,1,n){
		res+=(L==0);
		For(j,1,k){
			for (;pl[j]+1<=i&&f[i][c[j]]-f[pl[j]][c[j]]>=vl[j];add(++pl[j],1));
			for (;pr[j]+1<=i&&f[i][c[j]]-f[pr[j]][c[j]]> vr[j];add(++pr[j],-1));
			//cout<<i<<' '<<j<<' '<<
		}
		//cout<<res<<endl;
		ans+=res;
	}
	printf("%lld\n",ans);
}