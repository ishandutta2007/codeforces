#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=50005;
const double pi=acos(-1);
double k[N],b[N];
double dis[N],ang[N];
double a[N],x,y;
struct range{
	double l,r;
	int id;
	bool operator <(const range &a)const{
		return l<a.l;
	}
}p[N];
int n,m,t[N];
set<pair<double,int> > S;
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=t[x];
	return ans;
}
double read(){
	int x;
	scanf("%d",&x);
	return 0.001*x; 
} 
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	x=read(); y=read();
	scanf("%d",&m);
	For(i,1,n){
		k[i]=read(); b[i]=read();
		if (y<k[i]*x+b[i])
			ang[i]+=atan(k[i])+pi/2;
		else ang[i]=atan(k[i])-pi/2;
		dis[i]=fabs((k[i]*x+b[i]-y)/sqrt(k[i]*k[i]+1));
		//printf("%.10lf\n",dis[i]);
	}
	double l=0,r=1e11;
	For(T,1,100){
		double mid=(l+r)/2;
		int top=0;
		For(i,1,n){
			if (dis[i]>=mid) continue;
			double r=acos(dis[i]/mid);
			p[++top]=(range){ang[i]-r,ang[i]+r,i};
			for (;p[top].l<-pi;p[top].l+=2*pi);
			for (;p[top].r>pi;p[top].r-=2*pi);
			if (p[top].l>p[top].r)
				swap(p[top].l,p[top].r);
		}
		For(i,1,top) a[i]=p[i].r;
		sort(a+1,a+top+1);
		sort(p+1,p+top+1);
		memset(t,0,sizeof(t));
		int sum=0;
		For(i,1,top){
			int pl=lower_bound(a+1,a+top+1,p[i].l)-a;
			int pr=lower_bound(a+1,a+top+1,p[i].r)-a;
			sum+=ask(pr)-ask(pl-1);
			change(pr,1);
		}
		if (T==100&&r<=1e-18&&sum>=m)
			return puts("0.00000000000000000000"),0;
		if (sum<m) l=mid;
		else r=mid;
	}
	double Mid=(1-1e-9)*r,ans=0;
	int sum=0,top=0;
	For(i,1,n){
		if (dis[i]>=Mid) continue;
		double r=acos(dis[i]/Mid);
		p[++top]=(range){ang[i]-r,ang[i]+r,i};
		for (;p[top].l<-pi;p[top].l+=2*pi);
		for (;p[top].r>pi;p[top].r-=2*pi);
		if (p[top].l>p[top].r)
			swap(p[top].l,p[top].r);
	}
	sort(p+1,p+top+1);
	For(i,1,top){
		int idx=p[i].id;
		set<pair<double,int> >::iterator it;
		it=S.lower_bound(make_pair(p[i].l,-1));
		for (;it!=S.end()&&it->fi<p[i].r;it++){
			int idy=it->se;
			double t=(b[idy]-b[idx])/(k[idx]-k[idy]);
			double px=t,py=k[idx]*t+b[idx];
			sum++; ans+=sqrt((px-x)*(px-x)+(py-y)*(py-y));
			//printf("UPD %.10lf\n",sqrt((px-x)*(px-x)+(py-y)*(py-y)));	
		}
		S.insert(make_pair(p[i].r,idx)); 
	}
	ans-=(sum-m)*r;
	printf("%.20lf\n",ans);
}