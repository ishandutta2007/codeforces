//CF1188E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e6+16;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,m,w,d,t,ans,a[N],b[N];
int fac[N],ifac[N];
priority_queue<int,vector<int>,greater<int> > q;
int c(int x,int y){
	if(x<y||x<0||y<0)
		return 0;
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
int main()
{
	int i,x;
	n=1e6+5;
	fac[0]=1;
	for(i=1;i<=n;i=i+1)
		fac[i]=mul(fac[i-1],i);
	ifac[n]=fpow(fac[n]);
	for(i=n;i>=1;i=i-1)
		ifac[i-1]=mul(ifac[i],i);
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		m+=a[i];
		w=max(w,a[i]);
		q.push(a[i]);
		b[a[i]]++;
	}
	for(i=m;i>=0;i=i-1)
		b[i]+=b[i+1];
	for(i=0;i<=w;i=i+1){
		while(q.top()-d<0){
			if(!t){
				cout<<ans;
				return 0;
			}
			t--;
			x=q.top()+n;
			q.pop();
			q.push(x);
		}
		ad(ans,c(n+t-1,n-1));
		x=b[d];
		ad(ans,MO-c(n-x+t-1,n-1));
		t++;
		d++;
	}
	cout<<ans;
	return 0;
}