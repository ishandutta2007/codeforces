#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n=read(),m=read(),a[300005][11],msk[300005];
int cnt[260],lst[260],ans1,ans2;
inline int check(int mid){
	memset(cnt,0,sizeof(cnt));
	memset(msk,0,sizeof(msk));
	memset(lst,0,sizeof(lst));
	fz(i,1,n){
		fz(j,1,m){
			if(a[i][j]>=mid){
				msk[i]|=(1<<(j-1));
			}
		}
		cnt[msk[i]]++;
		lst[msk[i]]=i;
	}
	fz(i,0,(1<<m)-1){
		fz(j,0,(1<<m)-1){
			int k=i|j;
			if(k==((1<<m)-1)&&cnt[i]>0&&cnt[j]>0){
				ans1=lst[i],ans2=lst[j];
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	fz(i,1,n)	fz(j,1,m)	a[i][j]=read();
	int l=0,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	l=mid+1;
		else			r=mid-1;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}