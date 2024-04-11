#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

int n,a[100005],b[100005];
int s0,s1,s2;
void init(){
	char s[10];
	scanf("%s",s+1);
	for (int i=1;s[i];++i){
		if (s[i]=='+') s0=1;
		if (s[i]=='-') s1=1;
		if (s[i]=='*') s2=1;
	}
}
void solve1(char c){
	printf("%d",a[1]);
	For(i,2,n) printf("%c%d",c,a[i]);
	exit(0);
}
void solve2(){
	int p=-1;
	Rep(i,n,1) if (a[i]==0) p=i;
	printf("%d",a[1]);
	For(i,2,n) printf("%c%d",(i==p?'-':'*'),a[i]);
	exit(0);
}
void work(int l,int r){
	//cout<<"work "<<l<<' '<<r<<endl;
	if (l>r) return;
	ll Mul=1;
	For(i,l,r) Mul=min(Mul*a[i],1ll<<30);
	if (Mul==(1<<30)){
		int p1=l,p2=r;
		for (;a[p1]==1;++p1);
		for (;a[p2]==1;--p2);
		For(i,p1,p2-1) b[i]=0;
	}
	else{
		int top=1;
		pii q[40];
		int L[40],R[40];
		q[1]=pii(a[l],1);
		For(i,l+1,r)
			if (a[i]!=1||a[i]!=a[i-1])
				q[++top]=pii(a[i],1);
			else q[top].se++;
		L[1]=l; R[top]=r;
		R[0]=0;
		For(i,1,top-1){
			R[i]=L[i]+q[i].se-1;
			L[i+1]=R[i]+1;
		}
		//For(i,1,top) cout<<L[i]<<' '<<R[i]<<' '<<q[i].fi<<endl;
		int f[40],g[40];
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		For(i,1,top){
			if (f[i-1]+q[i].fi*q[i].se>=f[i]){
				f[i]=f[i-1]+q[i].fi*q[i].se;
				g[i]=-1;
			}
			int Mul=1;
			For(j,i,top){
				Mul*=q[j].fi;
				if (f[i-1]+Mul>f[j]){
					f[j]=f[i-1]+Mul;
					g[j]=i-1;
				}
			}
		}
		int p=top;
		for (;p!=0;)
			if (g[p]==-1)
				--p;
			else{
				int pp=g[p];
				//cout<<pp<<' '<<p<<endl;
				For(i,L[pp+1],R[p]-1)
					b[i]=0;
				p=pp;
			}
	}
}
void solve3(){
	For(i,1,n-1) b[i]=1;
	int la=0;
	For(i,1,n+1)
		if (!a[i]){
			work(la+1,i-1);
			la=i;
		}
	printf("%d",a[1]);
	For(i,2,n) printf("%c%d",(b[i-1]?'+':'*'),a[i]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	init();
	if (s0&&!s1&&!s2) solve1('+');
	if (s0&&s1&&!s2) solve1('+');
	if (!s0&&s1&&!s2) solve1('-');
	if (!s0&&!s1&&s2) solve1('*');
	if (!s0&&s1&&s2) solve2();
	solve3();
}