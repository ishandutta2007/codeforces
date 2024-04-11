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
const int mo1=1000000007;
const int mo2=1000000009;
const int N=1000005;
int n,m,nx[N];
char s1[N],s2[N],t[N];
int lcp[N],lcs[N];
void EXKMP(char *s,int n,int *nx){
	nx[1]=1;
	int k=1,a=1;
	For(i,2,n){
		nx[i]=nx[i-a+1];
		if (i+nx[i]>=k){
			k=max(k,i);
			for (;k<=n&&s[k]==s[k-i+1];++k);
			nx[i]=k-i; a=i;
		}
	}
}
void EXKMP(char *s,char *t,int n,int m,int *ex,int *nx){
	EXKMP(t,m,nx);
	int k=1,a=1;
	For(i,1,n){
		ex[i]=nx[i-a+1];
		if (i+ex[i]>=k){
			k=max(k,i);
			for (;k<=n&&k-i<m&&s[k]==t[k-i+1];++k);
			ex[i]=k-i; a=i;
		}
	}
}
struct Tarray{
	ll t[N];
	void change(int p,int v){
		for (p++;p<N;p+=p&(-p)) t[p]+=v;
	}
	ll ask(int p){
		ll ans=0;
		for (p++;p;p-=p&(-p)) ans+=t[p];
		return ans;
	}
}T1,T2;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s%s",s1+1,s2+1,t+1);
	EXKMP(s1,t,n,m-1,lcp,nx);
	reverse(t+1,t+m+1);
	reverse(s2+1,s2+n+1);
	EXKMP(s2,t,n,m-1,lcs,nx);
	reverse(lcs+1,lcs+n+1);
	ll ans=0;
	Rep(i,n,1){
		if (lcs[i]==m) --lcs[i];
		if (lcp[i]==m) --lcp[i];
		//cout<<i<<' '<<lcs[i]<<' '<<lcp[i]<<endl;
		T1.change(lcs[i],1);
		T2.change(lcs[i],lcs[i]);
		if (i+m-1<=n){
			T1.change(lcs[i+m-1],-1);
			T2.change(lcs[i+m-1],-lcs[i+m-1]);
		}
		if (!lcp[i]) continue;
		int v=max(m-lcp[i],1);
		ans+=T2.ask(m)-T2.ask(v-1);
		ans-=(T1.ask(m)-T1.ask(v-1))*1ll*(v-1);
	}
	printf("%lld\n",ans);
}