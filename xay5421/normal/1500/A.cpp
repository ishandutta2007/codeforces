// author: xay5421
// created: Sat Mar 13 18:14:55 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=3000005;
int n,a[N],b[N],id[N];
bool pd[N],vis[N];
pair<int,int>ans[N];
void out(int x){
	rep(i,1,n)if(!pd[i]&&a[i]==x){
		pd[i]=1,pt(i,' ');
		return;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(a[i]),id[i]=i,++b[a[i]];
	rep(i,1,N-1)if(b[i]>3){
		puts("YES"),out(i),out(i),out(i),out(i),exit(0);
	}
	vector<int>num;
	rep(i,1,N-1)if(b[i]>1){
		num.push_back(i);
	}
	if(SZ(num)>1){
		puts("YES");
		rep(i,0,1)rep(j,0,1)
			out(num[j]);
		return 0;
	}
	sort(id+1,id+1+n,[&](int x,int y){return a[x]<a[y];});
	int m=n;
	//rep(i,1,n)if(i==1||a[id[i]]!=a[id[i-1]])id[++m]=id[i];
	rep(i,1,m){
		rep(j,1,i-1){
			int d=a[id[i]]-a[id[j]];
			if(!ans[d].X)ans[d]=make_pair(id[i],id[j]);
			else if(id[j]!=ans[d].X&&id[j]!=ans[d].Y&&id[i]!=ans[d].X&&id[i]!=ans[d].Y)printf("YES\n%d %d %d %d\n",ans[d].Y,id[i],ans[d].X,id[j]),exit(0);
		}
	}
	puts("NO");
	return 0;
}