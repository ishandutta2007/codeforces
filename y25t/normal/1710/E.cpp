#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int n,m,x,y,a[N],b[N],c[N];ll sum[N];
int read(){
	int x=0;char c=getchar();
	while ((c<'0')||(c>'9'))c=getchar();
	while ((c>='0')&&(c<='9'))x=x*10+c-'0',c=getchar();
	return x;
}
bool check(int s){
	ll mx=0;bool flag=0;
	for(int i=1,j=m;i<=n;i++){
		while ((j)&&(a[i]+b[j]>s))j--;
		c[i]=j,sum[i]=sum[i-1]+j;
	}
	for(int i=m,j=0,pos=n;i;i--){
		while ((pos)&&(c[pos]<m-i))pos--;
		ll s=sum[pos]-(ll)(m-i)*pos;
		s-=(ll)i*(n-j)-(sum[n]-sum[j]);
		if (mx<s)mx=s,flag=0;
		if (mx==s)flag|=((y<=i)||(x<=pos));
		while ((j<n)&&(c[j+1]==i))j++;
	}
	return flag;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	x=a[1],y=b[1];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	x=lower_bound(a+1,a+n+1,x)-a;
	y=lower_bound(b+1,b+m+1,y)-b;
	int l=1,r=a[x]+b[y];
	while (l<r){
		int mid=(l+r>>1);
		if (check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}