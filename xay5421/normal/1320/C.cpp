#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int n,m,p,t[N<<2],tg[N<<2],tmp[N];
struct data{
	int x,y,z;
}a[N],b[N],c[N];
void psd(int k1){
	if(tg[k1]){
		tg[k1*2]+=tg[k1];
		t[k1*2]+=tg[k1];
		tg[k1*2+1]+=tg[k1];
		t[k1*2+1]+=tg[k1];
		tg[k1]=0;
	}
}
void upd(int k1){
	t[k1]=max(t[k1*2],t[k1*2+1]);
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1]=-tmp[k2];
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k3<k4||k5<k2)return;
	if(k4<=k2&&k3<=k5){
		t[k1]+=k6;
		tg[k1]+=k6;
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6);
	mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
signed main(){
	memset(tmp,63,sizeof(tmp));
	rd(n),rd(m),rd(p);
	for(int i=1;i<=n;++i)rd(a[i].x),rd(a[i].y);
	for(int i=1;i<=m;++i)rd(b[i].x),rd(b[i].y),tmp[b[i].x]=min(tmp[b[i].x],b[i].y);
	for(int i=1;i<=p;++i)rd(c[i].x),rd(c[i].y),rd(c[i].z);
	sort(a+1,a+1+n,[&](data x,data y){return x.x<y.x;});
	sort(b+1,b+1+m,[&](data x,data y){return x.x<y.x;});
	sort(c+1,c+1+p,[&](data x,data y){return x.x<y.x;});
	int ans=-1e18;
	bud(1,1,1000000);
	for(int i=1,j=0;i<=n;++i){
		while(j<p&&c[j+1].x<a[i].x){
			++j;
			mdf(1,1,1000000,c[j].y+1,1000000,c[j].z);
		}
		ans=max(ans,t[1]-a[i].y);
	}
	pt(ans,'\n');
	return 0;
}