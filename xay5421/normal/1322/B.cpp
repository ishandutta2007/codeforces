//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define VI vector<int>
//#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=400005;
int n,a[N],x[N],num0[N],num1[N],t[2][N];
void upd(int*t,int k1,int k2){
	for(int i=k1;i<=n;i+=i&-i)t[i]^=k2;
}
int qry(int*t,int k1){
	int res=0;
	for(int i=k1;i;i&=i-1)res^=t[i];
	return res;
}
signed main(){
//	freopen("a.in","r",stdin);
	rd(n);
	for(int i=1;i<=n;++i)rd(a[i]);
	int res=0;
	for(int b=0;b<=25;++b){
//		fprintf(stderr,"%d\n",b);
		*num0=0,*num1=0;int ans=0;
		for(int i=1;i<=n;++i)t[0][i]=0,t[1][i]=0;
		for(int i=1;i<=n;++i)
			if(a[i]>>b&1)x[i]=num1[++*num1]=a[i]&((1LL<<b)-1);
			else x[i]=num0[++*num0]=a[i]&((1LL<<b)-1);
//		int rk0=*num0,rk1=*num1;
		for(int i=1;i<=n;++i){
//			while(rk0>1&&num0[rk0-1]>=(1LL<<b)-x[i])--rk0;
//			while(rk1>1&&num1[rk1-1]>=(1LL<<b)-x[i])--rk1;
			int rk0=lower_bound(num0+1,num0+1+*num0,(1LL<<b)-x[i])-num0;
			int rk1=lower_bound(num1+1,num1+1+*num1,(1LL<<b)-x[i])-num1;
			if(a[i]>>b&1){
				ans^=qry(t[0],rk0-1);
				ans^=qry(t[1],n)^qry(t[1],rk1-1);
				upd(t[1],lower_bound(num1+1,num1+1+*num1,x[i])-num1,1);
			}else{
				ans^=qry(t[0],n)^qry(t[0],rk0-1);
				ans^=qry(t[1],rk1-1);
				upd(t[0],lower_bound(num0+1,num0+1+*num0,x[i])-num0,1);
			}
		}
		if(ans)res^=1LL<<b;
		VI v0,v1;
		for(int i=1;i<=n;++i){
			if(a[i]>>b&1)v1.push_back(a[i]);
			else v0.push_back(a[i]);
		}
		int m=0;
		for(int i=0;i<(int)v0.size();++i)a[++m]=v0[i];
		for(int i=0;i<(int)v1.size();++i)a[++m]=v1[i];
	}
	pt(res,'\n');
	return 0;
}