#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define fec(i,x) for (i=x.begin();i!=x.end();++i)
#define re(i,a) for (int i=0;i<a;++i)
#define clr(x) memset(x,0,sizeof x)
#define mp make_pair
#define N 5555
#define X first 
#define Y second
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1010
using namespace std;
typedef long long LL;
int n,m,w[maxn],x[maxn],rank[maxn];
pii pos[N];
int main(){
	read(n,m);rep(i,1,n)pos[i]=mp(1<<30,i);
	rep(i,1,n)read(w[i]);
	rep(i,1,m){
		read(x[i]);
		if(pos[x[i]].X==1<<30)pos[x[i]].X=i;
	}
	sort(pos+1,pos+n+1);
	rep(i,1,n)rank[i]=pos[i].Y;
	int ans=0;
	rep(i,1,m){
		int id=find(rank+1,rank+n+1,x[i])-rank;
		rep(j,1,id-1)ans+=w[rank[j]];
		dep(j,id,2)rank[j]=rank[j-1];
		rank[1]=x[i];
	}
	printf("%d\n",ans);
	return 0;
}