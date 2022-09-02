// author: xay5421
// created: Thu Dec 17 10:31:03 2020
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1005;
int n,st[N],top;
struct po{
	int x,y,c,id;
	bool operator!=(const po&k){return x!=k.x||y!=k.y;}
}a[N];
#define VEC(a,b) (b).x-(a).x,(b).y-(a).y
LL cross(LL a,LL b,LL c,LL d){return a*d-b*c;}
void sol(po k1,po k2,po k3,vector<po>v){
	if(k2.c==k3.c)swap(k1,k3);
	if(k1.c==k3.c)swap(k2,k3);
	if(cross(VEC(k3,k1),VEC(k3,k2))<0)swap(k1,k2);
	/*v.clear();
	rep(i,1,n)v.push_back(a[i]);*/
	{
		vector<po>vv;
		for(const auto&x:v){
			if(cross(VEC(k3,k1),VEC(k3,x))>0&&cross(VEC(k3,x),VEC(k3,k2))>0&&cross(VEC(k1,k2),VEC(k1,x))>0)vv.PB(x);
		}
		v=vv;
	}
	bool flg=0;
	po cur;
	rep(i,0,SZ(v)-1)if(v[i].c==k3.c){
		flg=1;
		cur=v[i];
	}
	if(flg){
		printf("%d %d\n",cur.id,k3.id);
		sol(k1,k2,cur,v),sol(k1,k3,cur,v),sol(k2,k3,cur,v);
	}else{
		sort(v.begin(),v.end(),[&](po a,po b){return cross(VEC(k1,a),VEC(k1,b))>0;});
		rep(i,0,SZ(v)-1)printf("%d %d\n",k1.id,v[i].id);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	if(n==1){
		puts("0");
		exit(0);
	}
	vector<po>v;
	rep(i,1,n)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c),a[i].id=i-1;
	{
		int pos=min_element(a+1,a+1+n,[&](po k1,po k2){return make_pair(k1.y,k1.x)<make_pair(k2.y,k2.x);})-a;
		swap(a[1],a[pos]);
		po bs=a[1];
		rep(i,1,n)a[i].x-=bs.x,a[i].y-=bs.y;
		sort(a+2,a+1+n,[&](po k1,po k2){return cross(k1.x,k1.y,k2.x,k2.y)>0;});
	}
	rep(i,1,n)v.PB(a[i]);
	{
		bool flg=1;
		rep(i,2,n)flg&=a[i].c==a[1].c;
		if(flg){
			printf("%d\n",n-1);
			rep(i,2,n){
				printf("%d %d\n",a[1].id,a[i].id);
			}
			return 0;
		}
	}
	{
		rep(i,1,n){
			while(top>1&&cross(VEC(a[st[top-1]],a[i]),VEC(a[st[top-1]],a[st[top]]))>0)--top;
			st[++top]=i;
		}
		int tem=a[st[1]].c;
		int l=1,r=top;
		while(l<=r&&a[st[l]].c==tem)++l;
		while(l<=r&&a[st[r]].c==tem)--r;
		if(l>r){
			printf("%d\n",n-2);
			rep(i,1,top-1)printf("%d %d\n",a[st[i]].id,a[st[i+1]].id);
			int pos=-1;
			rep(i,1,n){
				if(a[i].c!=a[st[1]].c){
					pos=i;
					break;
				}
			}
			rep(i,1,top){
				sol(a[st[i]],a[st[i%top+1]],a[pos],v);
			}
		}else{
			rep(i,l,r)if(a[st[i]].c!=a[st[l]].c){
				puts("Impossible");
				exit(0);
			}
			printf("%d\n",n-2);
			rep(i,1,top)if(a[st[i]].c==a[st[i%top+1]].c)printf("%d %d\n",a[st[i]].id,a[st[i%top+1]].id);
			rep(i,l,r-1){
				sol(a[st[l-1]],a[st[i]],a[st[i+1]],v);
			}
			rep(i,r+1,top)sol(a[st[r]],a[st[i]],a[st[i%top+1]],v);
			rep(i,1,l-2)sol(a[st[r]],a[st[i]],a[st[i%top+1]],v);
		}
	}
	return 0;
}