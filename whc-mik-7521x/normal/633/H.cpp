#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e4+50;
int n,m,q,x;
struct node{
    int val,id;
    bool operator <(const node &o)const{return val<o.val;}
}a[N];
int Fib[N],l[N],r[N],Max[N],Now[N];
long long Ans[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    sort(a+1,a+n+1);
	Fib[1]=Fib[2]=1;
    for(int i=3;i<=n;++i)Fib[i]=(Fib[i-1]+Fib[i-2])%m;
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
    	scanf("%d%d",&l[i],&r[i]);
    	Max[i]=-1;
	}
    for(int i=1;i<=n;++i){
    	x=a[i].val%m;
    	for(int j=1;j<=q;++j)
	    if(a[i].id>=l[j]&&a[i].id<=r[j]&&a[i].val!=Max[j]){
	        Max[j]=a[i].val;
	        Ans[j]+=Fib[++Now[j]]*x;
	    }
	}
    for(int i=1;i<=q;i++)printf("%lld\n",Ans[i]%m);
}