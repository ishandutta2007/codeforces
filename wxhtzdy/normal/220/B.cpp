#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
const int S=317;
int n,a[N],q,ans[N],tmp=0,cnt[N];
void Add(int x){
    if(x<=N){
        cnt[x]++;
        if(cnt[x]==x)tmp++;
        if(cnt[x]==x+1)tmp--;
    }
}
void Remove(int x){
    if(x<=N){
        cnt[x]--;
        if(cnt[x]==x)tmp++;
        if(cnt[x]==x-1)tmp--;
    }
}
struct Query{
	int l,r,i;
	Query(){}
	Query(int a, int b, int c){l=a,r=b,i=c;}
	inline bool operator < (const Query &b) const{
		return (r/S<b.r/S)||(r/S==b.r/S && l<b.l);
	}
} Q[N];
int main(){
    int n,q,i;
    scanf("%i %i",&n,&q);
    for(i=1;i<=n;i++)scanf("%i",&a[i]);
    for(i=0;i<q;i++)scanf("%i %i",&Q[i].l,&Q[i].r),Q[i].i=i;
    std::sort(Q,Q+q);
    int l=1,r=0;
    for(i=0;i<q;i++){
        while(r<Q[i].r)Add(a[++r]);
        while(r>Q[i].r)Remove(a[r--]);
        while(l<Q[i].l)Remove(a[l++]);
        while(l>Q[i].l)Add(a[--l]);
        ans[Q[i].i]=tmp;
    }
    for(int i=0;i<q;i++)printf("%i\n",ans[i]);
    return 0;
}