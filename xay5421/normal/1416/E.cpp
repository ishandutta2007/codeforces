#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int T,n,a[N],ans[N];
int sp;
struct DS{
	set<int>S;
	int k,b;
	void init(){
		S.clear();
		k=1,b=0;
	}
	int fun(int x){
		return k*x+b;
	}
	int ifun(int x){
		return (x-b)*k;
	}
	void push(int x){
		S.insert(ifun(x));
	}
	void adj(int l,int r){
		l=ifun(l),r=ifun(r);
		if(l>r)swap(l,r);
		if(S.empty())return;
		int x=*S.begin();
		while(x<l||x>r){
			S.erase(S.begin());
			if(S.empty())return;
			x=*S.begin();
		}
		x=*--S.end();
		while(x<l||x>r){
			S.erase(--S.end());
			if(S.empty())return;
			x=*--S.end();
		}
	}
	void flip(){
		k=-k,b=-b;
	}
}A;
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	rep(_,1,T){
		rd(n);
		rep(i,1,n)rd(a[i]);
		int l=0,r=-1;
		if(a[1]&1){
			ans[1]=2;
			l=1,r=a[1]-1;
			A.init();
		}else{
			ans[1]=1;
			l=0,r=-1;
			A.init();
			A.push(a[1]/2);
		}
		int pos=-1;
		rep(i,2,n){
			if(pos!=-1){
				A.init();
				A.push(pos);
				l=0,r=-1;
				pos=-1;
			}
			if(a[i]&1){
				A.flip();
				A.b+=a[i];
				A.adj(1,a[i]-1);
				l=max(0LL,a[i]-l);
				r=max(1LL,a[i]-r);
				swap(l,r);
				if(A.S.empty()&&l>r){
					ans[i]=ans[i-1]+2;
					A.init();
					l=1,r=a[i]-1;
				}else{
					ans[i]=ans[i-1]+1;
				}
			}else{
				auto chk=[&](int x)->bool{
					return (l<=x&&x<=r)||A.S.count(A.ifun(x));
				};
				bool flag=chk(a[i]/2);
				A.flip();
				A.b+=a[i];
				A.adj(1,a[i]-1);
				l=max(0LL,a[i]-l);
				r=max(1LL,a[i]-r);
				swap(l,r);
				if(A.S.empty()&&l>r){
					ans[i]=ans[i-1]+2;
					A.init();
					l=1,r=a[i]-1;
				}else{
					ans[i]=ans[i-1]+1;
				}
				if(flag){
					pos=a[i]/2;
					ans[i]=ans[i-1];
					l=0,r=-1;
				}else{
					if(ans[i-1]+1<ans[i]){
						ans[i]=ans[i-1]+1;
						A.init();
						l=0,r=-1;
					}
					A.push(a[i]/2);
				}
			}
		}
		pt(ans[n],'\n');
	}
	return 0;
}