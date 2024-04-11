#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
struct Shape{
	int x1,x2,y1,y2,d1,d2;
	Shape(){}
	Shape(int a,int b,int c,int d,int e,int f):x1(a),x2(b),y1(c),y2(d),d1(e),d2(f){}
	bool ckd(int x,int y){
		int d=x-y;
		return d1<=d&&d2>=d;
	}
	bool inside(int x,int y){
		return ckd(x,y)&&x1<=x&&x2>=x&&y1<=y&&y2>=y;
	}
};
Shape sec(Shape a,Shape b){
	return Shape(max(a.x1,b.x1),min(a.x2,b.x2),max(a.y1,b.y1),min(a.y2,b.y2),max(a.d1,b.d1),min(a.d2,b.d2));
}
bool on_seg(int x1,int x2,int x){return x1<=x&&x2>=x;}
const int N=300050;
const int inf=1e9+7;
char s[N];
int x[N],y[N];
Shape Solve(int n,int mid){
	Shape tmp=Shape(0,inf,0,inf,-inf,inf);
	for(int i=1;i<=n;i++){
		Shape now=Shape(x[i]-mid,x[i]+mid,y[i]-mid,y[i]+mid,x[i]-y[i]-mid,x[i]-y[i]+mid);
		tmp=sec(tmp,now);
	}
	//printf("mid: %i |%i %i %i %i %i %i\n",mid,tmp.x1,tmp.x2,tmp.y1,tmp.y2,tmp.d1,tmp.d2);
	return tmp;
}
pii Restore(Shape sh){
	vector<pii> can,pos;
	pos.pb({sh.x1,sh.x1-sh.d1});
	pos.pb({sh.x2,sh.x2-sh.d1});
	pos.pb({sh.x1,sh.x1-sh.d2});
	pos.pb({sh.x2,sh.x2-sh.d2});
	pos.pb({sh.d1+sh.y1,sh.y1});
	pos.pb({sh.d1+sh.y2,sh.y2});
	pos.pb({sh.d2+sh.y1,sh.y1});
	pos.pb({sh.d2+sh.y2,sh.y2});
	pos.pb({sh.x1,sh.y1});
	pos.pb({sh.x1,sh.y2});
	pos.pb({sh.x2,sh.y1});
	pos.pb({sh.x2,sh.y2});
	for(auto p:pos)if(sh.inside(p.first,p.second))can.pb(p);
	//for(auto p:pos)printf("<-%i %i\n",p.first,p.second);
	sort(can.begin(),can.end());
	//for(auto p:can)printf("->%i %i\n",p.first,p.second);
	return can.back();
}
bool test(Shape a){
	if(a.x1>a.x2)return 0;
	if(a.y1>a.y2)return 0;
	if(a.d1>a.d2)return 0;
	if(!(a.d1<=a.x2-a.y1))return 0;
	if(!(a.d2>=a.x1-a.y2))return 0;
	/*int y=a.x1-a.d1;
	if(!(y>=a.y1))return 0;
	y=a.x2-a.d2;
	if(!(y<=a.y2))return 0;
	int x=a.d1-a.y2;
	if(!(x<=a.x2))return 0;
	x=a.d2-a.y1;
	if(!(x>=a.x1))return 0;
	if(a.x2==0&&a.y2==0)return 0;*/
	pii pt=Restore(a);
	if(pt.first==0&&pt.second==0)return 0;
	return 1;
}
int main(){
	int n=ri();
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++){
			if(s[j]=='B')x[i]++;
			else y[i]++;
		}
	}
	int bot=0,top=N,mid,ans;
	while(top>=bot){
		mid=top+bot>>1;
		if(test(Solve(n,mid)))ans=mid,top=mid-1;
		else bot=mid+1;
	}
	Shape sh=Solve(n,ans);
	//printf("%i %i %i %i %i %i\n",sh.x1,sh.x2,sh.y1,sh.y2,sh.d1,sh.d2);
	printf("%i\n",ans);
	pii pt=Restore(sh);
	for(int i=1;i<=pt.first;i++)printf("B");
	for(int i=1;i<=pt.second;i++)printf("N");
	return 0;
}