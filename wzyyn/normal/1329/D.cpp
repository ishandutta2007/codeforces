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

const int N=200005;
set<int> S[30];
int n,m,q[N],c[30];
int pr[N],su[N],fa[N],t[N],Del[N];
pii ans[N];
char s[N];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void erase_node(int l,int r){
	for (l=get(l);l<=r;l=get(l))
		fa[l]=l+1,change(l,-1);
}
void erase_P(int p){
	Del[p]=1; --c[s[q[p]]-'a'];
	int l=pr[p],r=su[p];
	su[l]=r; pr[r]=l;
	if (l!=1&&s[q[l]]!=s[q[p]]){
		S[s[q[l]]-'a'].erase(l);
		S[s[q[p]]-'a'].erase(l);
	}
	if (r<=m&&s[q[r]]!=s[q[p]]){
		S[s[q[p]]-'a'].erase(p);
		S[s[q[r]]-'a'].erase(p);
	}
	if (l!=1&&r<=m&&s[q[l]]!=s[q[r]]){
		S[s[q[l]]-'a'].insert(l);
		S[s[q[r]]-'a'].insert(l);
	}
}
int count_ans(){
	memset(c,0,sizeof(c));
	int res=0,mx=0;
	For(i,2,n) if (s[i]==s[i-1])
		res++,mx=max(mx,++c[s[i]-'a']);
	return max((res+1)/2,mx);
}
void solve(){
	*q=0; 
	scanf("%s",s+1);
	n=strlen(s+1);
	m=1; q[1]=1;
	For(i,2,n)
		if (s[i]==s[i-1])
			q[++m]=i;
	q[m+1]=n+1;
	For(i,1,n) t[i]=0;
	For(i,1,n) change(i,1);
	For(i,0,m+1) pr[i]=i-1,su[i]=i+1,Del[i]=0;
	pr[0]=0; su[m+1]=m+1;
	For(i,1,n+1) fa[i]=i;
	For(i,0,25) S[i].clear();
	For(i,2,m-1)
		if (s[q[i]]!=s[q[i+1]]){
			S[s[q[i]]-'a'].insert(i);
			S[s[q[i+1]]-'a'].insert(i);
		}
	int top=0;
	int tms=count_ans();
	For(i,1,tms){
		int ch=0;
		For(j,1,25) if (c[j]>c[ch]) ch=j;
		if (S[ch].size()!=0){
			int p1=*S[ch].begin(),p2=su[p1];
			//cout<<p1<<' '<<p2<<' '<<q[p1]<<' '<<q[p2]<<endl;
			ans[++top]=pii(ask(q[p1]),ask(q[p2]-1));
			erase_node(q[p1],q[p2]-1);
			erase_P(p1); erase_P(p2);
		}
		else break;
	}
	For(i,2,m)
		if (!Del[i]){
			ans[++top]=pii(1,ask(q[i]-1));
			erase_node(1,q[i]-1);
		}
	assert(top==tms);
	ans[++top]=pii(1,ask(n));
	printf("%d\n",top);
	For(i,1,top) printf("%d %d\n",ans[i].fi,ans[i].se);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
		//freopen("1.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}