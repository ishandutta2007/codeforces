#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
int mod=998244353;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
const int N=200050;
int base[N],ibase[N],pref[N];
struct Node{
	int zero,rig,lef,sz,cnt;
	int hsh;
};
Node Make(char s){
	Node ans;
	ans.sz=1;
	if(s=='0')ans.rig=ans.lef=ans.cnt=ans.hsh=0,ans.zero=1;
	else ans.rig=ans.lef=ans.cnt=1,ans.zero=0,ans.hsh=1;
	return ans;
}
Node merge(Node a,Node b){
	Node ans;
	ans.zero=a.zero+b.zero;
	ans.sz=a.sz+b.sz;
	ans.lef=a.lef==a.sz?a.sz+b.lef:a.lef;
	ans.rig=b.rig==b.sz?b.sz+a.rig:b.rig;
	if(a.rig%2==1){
		cksub(a.hsh,mul(base[a.cnt-1],a.zero+1));
		a.cnt--;
	}
	if(b.lef%2==1){
		cksub(b.hsh,1);
		ckmul(b.hsh,ibase[1]);
		b.cnt--;
	}
	if((a.rig+b.lef)%2==1){
		if(b.cnt)ckadd(b.hsh,mul(a.zero,pref[b.cnt-1]));
		ans.hsh=add(a.hsh,mul(base[a.cnt],a.zero+1));
		ckadd(ans.hsh,mul(base[a.cnt+1],b.hsh));
		ans.cnt=a.cnt+b.cnt+1;
	}else{
		if(b.cnt)ckadd(b.hsh,mul(a.zero,pref[b.cnt-1]));
		ans.hsh=add(a.hsh,mul(base[a.cnt],b.hsh));
		ans.cnt=a.cnt+b.cnt;
	}
	return ans;
}
/*struct Node{
	int zero,rig,lef,sz,cnt;
	int hsh;
};
Node Make(char s){
	Node ans;
	ans.sz=1;
	if(s=='0')ans.rig=ans.lef=ans.cnt=ans.hsh=0,ans.zero=1;
	else ans.rig=ans.lef=ans.cnt=1,ans.zero=0,ans.hsh=mul(base[1],1);
	return ans;
}
Node merge(Node a,Node b){
	Node ans;
	ans.zero=a.zero+b.zero;
	ans.sz=a.sz+b.sz;
	ans.lef=a.lef==a.sz?a.sz+b.lef:a.lef;
	ans.rig=b.rig==b.sz?b.sz+a.rig:b.rig;
	if(a.rig%2==1){
		cksub(a.hsh,mul(base[a.cnt],a.zero+1));
		a.cnt--;
	}
	if(b.lef%2==1){
		cksub(b.hsh,mul(base[1],1));
		ckmul(b.hsh,ibase[1]);
		b.cnt--;
	}
	if((a.rig+b.lef)%2==1){
		ckadd(b.hsh,mul(a.zero,pref[b.cnt]));
		ans.hsh=add(a.hsh,mul(base[a.cnt+1],a.zero+1));
		ckadd(ans.hsh,mul(base[a.cnt+1],b.hsh));
		ans.cnt=a.cnt+b.cnt+1;
	}else{
		ckadd(b.hsh,mul(a.zero,pref[b.cnt]));
		ans.hsh=add(a.hsh,mul(base[a.cnt],b.hsh));
		ans.cnt=a.cnt+b.cnt;
	}
	return ans;
}*/
const int M=2*N;
Node node[M];
int ls[M],rs[M],tsz,root;
char s[N];
void Build(int &c,int ss,int se){
	c=++tsz;
	if(ss==se){
		node[c]=Make(s[ss]);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=merge(node[ls[c]],node[rs[c]]);
}
Node Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return node[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe);
	return merge(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int ans[N],x[N],y[N],len[N],n,q;
int one[N];
void Solve(int m,int b){
	mod=m;
	base[0]=1;base[1]=b;
	for(int i=2;i<=n;i++)base[i]=mul(base[i-1],base[1]);
	pref[0]=1;
	for(int i=1;i<=n;i++)pref[i]=add(base[i],pref[i-1]);
	//for(int i=0;i<=n;i++)ibase[i]=inv(base[i]);
	ibase[1]=inv(base[1]);
	tsz=root=0;
	Build(root,1,n);
	for(int i=1;i<=q;i++)if(ans[i]){
		Node A=Get(root,1,n,x[i],x[i]+len[i]-1);
		Node B=Get(root,1,n,y[i],y[i]+len[i]-1);
		if(A.hsh!=B.hsh)ans[i]=0;
		//printf("q:%i %i %i\n",i,A.hsh,B.hsh);
	}
}
int main(){
	scanf("%i",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)one[i]=one[i-1]+(s[i]=='1');
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i %i %i",&x[i],&y[i],&len[i]);
		if(one[x[i]+len[i]-1]-one[x[i]-1]==one[y[i]+len[i]-1]-one[y[i]-1])ans[i]=1;
	}
	Solve(998244353,77789);
	Solve(1e9+9,5555577);
	Solve(1e9+7,44444777);
	Solve(998244353,5003123);
	for(int i=1;i<=q;i++){
		if(ans[i])printf("Yes\n");
		else printf("No\n");
	}
	//for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
	//	printf("%i %i %i\n",i,j,Get(root,1,n,i,j).hsh);
	//}
	return 0;
}