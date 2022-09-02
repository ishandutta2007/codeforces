#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=55;
int n;
void fun(vector<int>&a){
	vector<int>v(a);
	sort(v.begin(),v.end());
	rep(i,0,SZ(a)-1)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
}
void work(vector<int>&a,vector<int>&b){
	vector<int>A,B;
	for(int i=0,j;i<SZ(a);i=j){
		j=i;
		int sum=0;
		while(j<SZ(a)&&a[i]+j-i==a[j])sum+=b[j],++j;
		A.PB(a[i]);
		B.PB(sum);
	}
	a=A,b=B;
}
int tot;
void sol(vector<int>a,vector<int>b,int flag){
	fun(a);
	work(a,b);
	if(SZ(a)<=1)return;
	fun(a);
	rep(i,0,SZ(a)-1){
		vector<int>num;
		rep(j,0,i-1){
			if(a[j]==a[i]+1){
					int sum=0;
					rep(k,0,j-1)sum+=b[k];
					if(sum)num.PB(sum);
					
					sum=b[j];
					if(sum)num.PB(sum);
					
					sum=0;
					rep(k,j+1,i)sum+=b[k];
					if(sum)num.PB(sum);
					
					sum=0;
					rep(k,i+1,SZ(a)-1)sum+=b[k];
					if(sum)num.PB(sum);
				if(flag){
					pt(SZ(num),' ');
					rep(k,0,SZ(num)-1)pt(num[k],' ');
					puts("");
				}else{
					++tot;
				}
				vector<int>na,nb;
				rep(k,i+1,SZ(a)-1)na.PB(a[k]),nb.PB(b[k]);
				rep(k,j+1,i)na.PB(a[k]),nb.PB(b[k]);
				na.PB(a[j]),nb.PB(b[j]);
				rep(k,0,j-1)na.PB(a[k]),nb.PB(b[k]);
				sol(na,nb,flag);
				return;
			}
		}
	}
}
signed main(){
	rd(n);
	vector<int>a(n),b(n,1);
	rep(i,0,n-1)rd(a[i]);
	sol(a,b,0);
	pt(tot,'\n');
	sol(a,b,1);
	return 0;
}