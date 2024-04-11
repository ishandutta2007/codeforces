#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n;ll s,f[N],g[N];
struct data{
	ll v,c;
	ll f(ll x){return x*v+c;}
	ll get(ll x){return (x-c+v-1)/v;}
	bool operator<(const data&b)const{return c^b.c?c<b.c:v>b.v;}
}a[N],q[N];
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i].v,&a[i].c);
		if(a[i].c>=s){--i,--n;continue;}
	}
	sort(a+1,a+1+n);
	int nn=0;
	for(int i=1;i<=n;++i)if(a[i].v>a[nn].v)a[++nn]=a[i];
	n=nn;
	a[++n]=(data){0x3f3f3f3f,s};
	int he=1,ta=1;
	q[1]=(data){a[1].v,0};
	for(int i=2;i<=n;++i){
//		printf("i=%d:",i);
//		for(int i=he;i<=ta;++i)printf("{%lld,%lld}",q[i].v,q[i].c);puts("");
		while(he<ta){
			ll k1=q[he].get(a[i].c),k2=q[he+1].get(a[i].c);
			if(k1>k2||(k1==k2&&q[he].f(k1)<=q[he+1].f(k2)))++he;else break;
		}
//		if(he<ta&&(q[he+1].c-q[he].c)/(q[he].v-q[he+1].v)*q[he].v+q[he].c<a[i].c){
//			if(i==11)printf("%lld\n",848623162124ll),exit(0);
//			else printf("%d\n",i),assert(0);
//		}
		f[i]=q[he].get(a[i].c),g[i]=q[he].f(f[i])-a[i].c;
//		assert(g[i]>=0),assert(g[i]<q[he].v);
		data k1=(data){a[i].v,g[i]-f[i]*a[i].v};
		while(ta>he&&(k1.c-q[ta].c)*(q[ta-1].v-q[ta].v)<=(q[ta-1].c-q[ta].c)*(k1.v-q[ta].v))--ta;
		q[++ta]=k1;
	}
	cout<<f[n]<<endl;
	return 0;
}