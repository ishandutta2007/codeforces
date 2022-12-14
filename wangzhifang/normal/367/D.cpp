#include <cstdio>
#include <cstring>
#define max_m 20
#define max_n 100000
#define INF 2147483647
using namespace std;
typedef const int& ci;
int a[1<<max_m];
void fwt(ci l){
	for(int i=1,b=1; (i<<=1)<=l; b=i)
		for(int j=0; j<l; j+=i)
			for(int k=0; k<b; ++k)
				a[j|k]+=a[j|b|k];
}
int pos[max_n+1];
int ton[max_m];
void ins(ci x,int&now){
	++ton[x]==1&&(now^=1<<x);
}
void del(ci x,int&now){
	--ton[x]||(now|=1<<x);
}
template<typename T>void minify(T&x,const T&y){
	y<x&&(x=y);
}
int main(){
	int n,m,d,now,num,ans=INF;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=-1,siz,x; ++i<m; ){
		scanf("%d",&siz);
		for(++siz; --siz; pos[x]=i)
			scanf("%d",&x);
	}
	memset(a,0,sizeof(a)),memset(ton,0,sizeof(ton)),now=(num=1<<m)-1;
	for(int*i=pos,*ed=pos+d; ++i<=ed; ins(*i,now));
	a[now]=1;
	for(int*l=pos,*r=pos+d,*ed=pos+n; ++r<=ed; a[now]=1)
		ins(*r,now),del(*++l,now);
//	for(int i=-1; ++i<num; printf("%d:%d\n",i,a[i]));
	fwt(num);
//	for(int i=-1; ++i<num; printf("%d:%d\n",i,a[i]));
	for(int i=0; ++i<num; a[i]||(minify(ans,__builtin_popcount(i)),1));
	printf("%d\n",ans);
	return 0;
}