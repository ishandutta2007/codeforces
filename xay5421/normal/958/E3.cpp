#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=20005;
int n,ans[N];
struct data{
	int x,y,t,id;
}a[N],ba;
bool cmp1(const data&k1,const data&k2){return k1.y^k2.y?k1.y<k2.y:k1.x<k2.x;}
bool cmp2(const data&k1,const data&k2){return 1LL*(k1.y-ba.y)*(k2.x-ba.x)<1LL*(k2.y-ba.y)*(k1.x-ba.x);}
void sol(int l,int r){
//	D("sol:%d %d\n",l,r);
	if(l>r)return;
	int pos=min_element(a+l,a+r+1,cmp1)-a;
	swap(a[l],a[pos]),ba=a[l];
	sort(a+l+1,a+r+1,cmp2);
	int k=r,s=0;
	for(;ba.t==a[k].t||s;--k)if(ba.t==a[k].t)++s;else --s;
	if(ba.t)ans[a[k].id]=a[l].id;
	else ans[a[l].id]=a[k].id;
	sol(l+1,k-1); 
	sol(k+1,r);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%d%d",&a[i].x,&a[i].y),a[i].t=(i>n),a[i].id=i;
	sol(1,n*2);
	rep(i,1,n)printf("%d\n",ans[i]-n);
	return 0;
}