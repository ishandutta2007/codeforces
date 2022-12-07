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
int S[16][65536];
void init(){
	For(i,0,65535){
		int a0=i&15,a1=(i>>4)&15,a2=(i>>8)&15,a3=(i>>12);
		int tmp=max(max(a0,a1),max(a2,a3));
		For(j,0,15)
			if (i&(1<<max(tmp,j)))
				S[j][i]=1;
	}
	For(j,0,15)
		For(i,1,65535)
			S[j][i]+=S[j][i-1];
}
int l[25],r[25];
int v[16][16];
ll f[16][16];
void inputt(int *a){
	char s[25];
	scanf("%s",s);
	int l=strlen(s);
	reverse(s,s+l);
	For(i,0,15) a[i]=0;
	For(i,0,l-1)
		if (s[i]<='9') a[i]=s[i]-'0';
		else a[i]=s[i]-'a'+10;
	//Rep(i,l-1,0) cout<<a[i]<<' '; cout<<endl; 
}
ll solve(int b,int mx,int fl1,int fl2){
	if (b==3){
		if (!fl1&&!fl2) return S[mx][65535];
		int vl=0,vr=0;
		Rep(j,3,0) vl=vl*16+l[j];
		Rep(j,3,0) vr=vr*16+r[j];
		if (!fl1) vl=0;
		if (!fl2) vr=65535;
		return S[mx][vr]-(vl?S[mx][vl-1]:0);
	}
	if (!fl1&&!fl2&&v[b][mx])
		return f[b][mx];
	ll ans=0;
	For(i,fl1?l[b]:0,fl2?r[b]:15)
		ans+=solve(b-1,max(mx,i),fl1&(i==l[b]),fl2&(i==r[b]));
	if (!fl1&&!fl2) v[b][mx]=1,f[b][mx]=ans;
	return ans;
}
void solve(){
	inputt(l);
	inputt(r);
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
	printf("%lld\n",solve(15,0,1,1));
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}