#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
struct data{
	long long val,pos;
}a[100005];
inline long long cmp(data a,data b){
	return a.val>b.val;
}
long long an,anan,sum[100005],m,n,A,cf,cm,ans,summ,b[100005];
inline bool check(long long x,long long money,long long first){
	long long l=first,r=n+1;
	while(l<r){
		long long mid=l+r>>1;
		if(a[mid].val>=x)l=mid+1; else r=mid;
	}
	return money>=(n-l+1)*x-sum[l];
}
inline long long find(long long x,long long y){
	long long l=a[n].val,r=1000000000;
	while(l<r){
		long long mid=(l+r)>>1; mid++;
		if(check(mid,x,y))l=mid; else r=mid-1;
	}
	if(l>A)return A;
	return l;
}
int main(){
    n=read(); A=read(); cf=read(); cm=read(); m=read();
    for(long long i=1;i<=n;i++){
    	b[i]=a[i].val=read(); a[i].pos=i;
	}
	sort(&a[1],&a[n+1],cmp);
	for(long long i=n;i;i--){
		sum[i]=sum[i+1]+a[i].val;
	}ans=-1;
	if(m>=n*A-sum[1]){
		writeln(n*cf+A*cm);
		for(int i=1;i<=n;i++){
			write(A); putchar(' ');
		}
		return 0;
	}
	for(long long i=0;i<n;i++){
		if(summ>m)break;
		long long tt=find(m-summ,i+1);
		long long t=i*cf+tt*cm; 
		if(t>ans){
		    ans=t; 
		    an=tt; anan=i;
		}
		summ+=A-a[i+1].val;
	}
	writeln(ans);
	for(long long i=1;i<=anan;i++)a[i].val=A;
	for(long long i=anan+1;i<=n;i++)a[i].val=an;
	for(long long i=1;i<=n;i++)b[a[i].pos]=max(a[i].val,b[a[i].pos]);
	for(long long i=1;i<=n;i++){
		write(b[i]); putchar(' ');
	}
}