#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 2147483647
#define sizof(n) n<<2
#define pus(pos) sa[cur[a[pos]]--]=pos
#define pul(pos) sa[++cur[a[pos]]]=pos
#define arrset std::memset
#define arrcpy std::memcpy
#define induce_sort(lmspos)\
	arrset(sa+1,-1,sizof(n)),arrcpy(cur,sum,sizof(kp1));\
	for(int*i=lmspos+mp1; --i>lmspos; pus(*i));\
	arrcpy(cur+1,sum,sizof(k));\
	for(int*i=sa; ++i<=fin; *i>1&&!tp[*i-1]&&(pul(*i-1)));\
	arrcpy(cur,sum,sizof(kp1));\
	for(int*i=sa+np1; --i>sa; *i>1&&tp[*i-1]&&(pus(*i-1)))
void sais(int*a,const int n,const int k,int*sa){
	const int np1=n+1,kp1=k+1;
	bool*tp=new bool[np1];
	tp[n]=1;
	for(int i=n; --i; tp[i]=(a[i]==a[i+1])?tp[i+1]:(a[i]<a[i+1]));
	int*lms=new int[n+4>>1],*num=new int[np1],m=0;
	num[1]=-1;
	for(int i=1; ++i<=n; num[i]=(tp[i]&&!tp[i-1])?(lms[++m]=i,m):-1);
	const int mp1=m+1;
	int*sum=new int[kp1],*cur=new int[kp1];
	arrset(sum,0,sizof(kp1));
	for(int*i=a+np1; --i>a; ++sum[*i]);
	for(int*i=sum; ++i<=sum+k; *i+=*(i-1));
	const int*fin=sa+n;
	induce_sort(lms);
	lms[mp1]=n;
	int*a1=new int[mp1],k1=0;
	for(int i=0,x,y; ++i<=n; )
		if(~(x=num[sa[i]]))
			if(!k1||lms[x+1]-lms[x]!=lms[y+1]-lms[y])
				a1[y=x]=++k1;
			else
				for(int p1=lms[x],p2=lms[y]; (p1<lms[x+1]||(a1[y=x]=k1,0))&&(a[p1]==a[p2]&&tp[p1]==tp[p2]||(a1[y=x]=++k1,0)); ++p1,++p2);
	if(k1==m)
		for(int i=0; ++i<=m; sa[a1[i]]=i);
	else
		sais(a1,m,k1,sa);
	for(int i=0; ++i<=m; a1[i]=lms[sa[i]]);
	induce_sort(a1);
	delete[] tp,
	delete[] lms,
	delete[] num,
	delete[] sum,
	delete[] cur,
	delete[] a1;
}
#define max_n 5000
#define max_char 256
char s[max_n+2];
int a[max_n+2];
int sa[max_n+2];
int ton[max_char+1];
template <typename T,typename vT> inline void maxi(T&x,vT val){
	(val>x)&&(x=val);
}
template <typename T,typename vT> inline void mini(T&x,vT val){
	(val<x)&&(x=val);
}
template <typename T>void write(T x){
	x>9&&(write(x/10),1);
	putchar(x%10^'0');
}
template <typename T>void write(T x,char ch){
	write(x);
	putchar(ch);
}
int rk[max_n+2];
int height[max_n+2];
int h[max_n+2][max_n+2];
int f[max_n+2];
int main(){
	int n,ca,cb,minc=max_char,maxc=0;
	scanf("%d%d%d\n%s",&n,&ca,&cb,s+1);
	++n,memset(ton,0,sizeof(ton));
	for(int i=0; ++i<n; ton[s[i]]=1,maxi(maxc,s[i]),mini(minc,s[i]));
	ton[minc-1]=1;
	for(int i=minc-1; ++i<=maxc; ton[i]+=ton[i-1]);
	for(int i=0; ++i<n; a[i]=ton[s[i]]);
	a[n]=1;
	sais(a,n,ton[maxc],sa);
	for(int i=0; ++i<=n; rk[sa[i]]=i);
	for(int i=0,j,x=0; ++i<=n; height[rk[i]]=x)
		for(j=sa[rk[i]-1],x&&(--x); a[i+x]==a[j+x]; ++x);
	for(int i=0; ++i<=n; ){
		h[i][i]=INF;
		for(int j=i; --j; h[i][j]=min(h[i][j+1],height[j+1]));
		for(int j=i; ++j<=n; h[i][j]=min(h[i][j-1],height[j]));
	}
	memset(f,127,sizeof(f)),--n;
	f[1]=ca;
//	printf("*%d %d %s\n",ca,cb,s+1);
	for(int i=0,x; ++i<n; mini(f[i+1],f[i]+ca)){
//		printf("&f[%d]=%d\n",i,f[i]);
		x=0;
		for(int j=0; ++j<=i; maxi(x,min(h[rk[i+1]][rk[j]],i-j+1)));
//		printf("**%d %d\n",x,h[rk[i+1]][rk[1]]);
		mini(f[i+x],f[i]+cb);
//		printf("&&%d\n",f[4]);
	}
	printf("%d\n",f[n]);
	return 0;
}