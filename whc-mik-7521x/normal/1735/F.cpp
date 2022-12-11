#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+10;
long long t,n,p[N],q[N];
long long a,b;
struct node{
    long long x,y;
    mutable long double len;
    bool operator<(const node b)const{return x*b.y<b.x*y;}
};
long double k(node kk){return 1.l*kk.x/kk.y;}
long double r(node kk){return kk.len*k(kk);}
int main(){
    long long t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&a,&b);
        for(long long i=1;i<=n;i++)scanf("%lld",&p[i]);
        for(long long i=1;i<=n;i++)scanf("%lld",&q[i]);
        if(!a&&!b){while(n--)puts("0");continue;}
        set<node>st;
        long double sum=a,res1=b,res2=a;
        for(long long i=1;i<=n;i++){
            if(st.count(node{p[i],q[i],0}))st.find(node{p[i],q[i],0})->len+=q[i]*2;
            else st.insert(node{p[i],q[i],q[i]*2.l});
            res1-=q[i];
            res2-=p[i];
            while(res1+st.begin()->len<0)res1+=st.begin()->len,sum-=st.begin()->len*k(*st.begin()),st.erase(st.begin());
            if(res1<0)sum+=k(*st.begin())*res1,st.begin()->len+=res1,res1=0;
            while(res2+r(*st.rbegin())<0)res2+=r(*st.rbegin()),st.erase(*st.rbegin());
            if(res2<0)st.rbegin()->len+=res2/k(*st.rbegin()),res2=0;
            sum+=p[i];
            printf("%.9Lf\n",sum);
        }
    }
    return 0;
}