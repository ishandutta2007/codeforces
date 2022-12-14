#include <cstdio>
#include <algorithm>
using namespace std;
#define max_n 200000
#define INF 2147483647
int data[max_n+2],id[max_n+2],rnk[max_n+2],val[max_n+2];
typedef const int& ci;
bool cmp(ci a,ci b){
	return data[a]<data[b];
}
int main() {
    int n,m,p,q,l,r;
    bool flg;
    scanf("%d%d",&n,&m);
    for(int i=0; ++i<=n; scanf("%d",data+i),id[i]=i);
    stable_sort(id+1,id+n+1,cmp);
    for(int i=0; ++i<=n; rnk[id[i]]=i,val[i]=data[id[i]]);
    val[n+1]=INF;
    for(++m; --m; ){
        scanf("%d%d",&p,&l);
        q=upper_bound(val,val+n+2,val[p=rnk[p]]+l)-val-1;
        l-=val[q]-val[p];
        for(p=q,flg=0; (q=(flg?(upper_bound(val+1,val+n+2,val[p]+l*2*flg-l)-val-1):(lower_bound(val+1,val+n+2,val[p]+l*2*flg-l)-val)))!=p; l%=r)
            ((l/(r=abs(val[p]-val[q])))&1)&&(p=q,flg^=1);
        printf("%d\n",id[p]);
	}
    return 0;
}