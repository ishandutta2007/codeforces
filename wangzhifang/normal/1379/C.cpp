#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_m 100000
#define cs const
using namespace std;
struct node{
	int s,t;
	friend bool operator <(const node&x,const node&y){
		if(x.t!=y.t)
			return x.t>y.t;
		return x.s>y.s;
	}
};
node a[max_m+1],b[max_m+1];
bool f[max_m+1];
template<typename T>void read(T&x){
	int ch;
	while(!isdigit(ch=getchar()));
	for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
}
template<typename T1,typename T2>void read(T1&x,T2&y){
	read(x);
	read(y);
}
template<typename T>void write(cs T&x){
	if(x>=10)
		write(x/10);
	putchar((x%10)|'0');
}
template<typename T>void writeln(cs T&x){
	write(x);
	putchar('\n');
}
void test(){
	int n,m,cnt=0,k;
	long long ans=0,sum=0,tmp;
	read(n,m);
	node*eda=a+m;
	for(int i=0; ++i<=m; read(a[i].s,a[i].t));
	stable_sort(a+1,eda+1);
	for(node*i=a+1,*j=a+1; ++i<=eda; i->s>j->s?(swap(*++j,*i),1):(++cnt));
	for(int i=0; ++i<=m; b[i].s=i,b[i].t=a[i].s);
	stable_sort(b+1,b+(k=m)+1);
	m-=cnt,a[0].s=0,memset(f,0,sizeof(f));
	for(int i=0,j=0; ++i<=m; (tmp=sum+(f[i]?(long long)(n-j)*a[i].t:(long long)(n-j-1)*a[i].t+a[i].s))>ans&&(ans=tmp))
		for(; j<n+int(f[i])-1&&j<k&&b[j+1].t>a[i].t; sum+=b[j].t,f[b[j].s]=1)
			++j;
	writeln(ans);
}
int main(){
	int t;
	read(t);
	for(++t; --t; test());
	return 0;
}