#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
const int N=2005,mod=998244353;
int a[N],b[N],pa[N],w[N],bin[N];
int n,m,ans;
char s[N];
 
inline int getpa(int x){
	if(pa[x]==x)return x;
	int p=getpa(pa[x]);
	w[x]^=w[pa[x]];
	return pa[x]=p;
}
inline int link(int a,int b,int c){
	if(getpa(a)!=getpa(b)){
		w[pa[a]]=w[a]^w[b]^c;
		pa[pa[a]]=pa[b];
	}
	else if(w[a]^w[b]^c)return 0;
	return 1;
}
 
int solve(int A,int B){
	memset(pa,0,sizeof pa);
	memset(w,0,sizeof w);
	rep(i,1,B*2+3)pa[i]=i;
	m=0;int zero=++m;
	rep(i,0,B)a[i]=++m,(i>A?link(zero,m,0):0);
	rep(i,0,B)b[i]=++m;
	link(zero,a[0],1),link(zero,b[0],1);
	for(int i=0,j=A;i<j;i++,j--)
		if(!link(a[i],a[j],0))return 0;
	for(int i=0,j=B;i<j;i++,j--)
		if(!link(b[i],b[j],0))return 0;
	rep(i,0,B)
		if(s[i]!='?'&&!link(a[i],b[i],s[i]-'0'))return 0;
	int owo=0;
	rep(i,1,m)owo+=(pa[i]==i);
	return bin[owo-1];
}
 
int main(){
	scanf("%s",s);
	n=strlen(s);
	reverse(s,s+n);
	bin[0]=1;
	rep(i,1,n*2)bin[i]=bin[i-1]*2%mod;
	rep(i,1,n-1)
		ans=(ans+solve(i-1,n-1))%mod;
	printf("%d\n",ans);
	return 0;
}