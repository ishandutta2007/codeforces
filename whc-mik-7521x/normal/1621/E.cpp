#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct BIT{
    int ts[N];
    int ask(int x){
        int res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,int d){
        for(;x<N;x+=x&-x)ts[x]+=d;
    }
    void del(int x){
        for(int i=0;i<=x;i++){
            ts[i]=0;
        }
    }
};
struct grop{
    int k,l,r;
    long long sum;
    double ave;
    vector<int>v;
    bool operator<(const grop bb)const{
        return ave>bb.ave;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        grop b[N];
        int cnt=1,ans[N<<1],a[N];
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i].k);
            b[i].l=cnt;
            cnt+=b[i].k;
            b[i].r=cnt-1;
            b[i].sum=0;
            for(int o=1;o<=b[i].k;o++){
                int x;
                scanf("%d",&x);
                b[i].v.push_back(x);
                b[i].sum+=x;
            }
            b[i].ave=b[i].sum*1.0/b[i].k;
        }
        for(int i=1;i<cnt;i++)ans[i]=0;
        stable_sort(a+1,a+n+1,[](int k1,int k2){return k1>k2;});
        stable_sort(b+1,b+m+1);  
        BIT st,pe,nx;
        st.del(m);
        pe.del(m);
        nx.del(m);
        for(int i=1;i<=m;i++)if(b[i].ave<=a[i])st.add(i,1);
        for(int i=2;i<=m;i++)if(b[i].ave<=a[i-1])pe.add(i,1);
        for(int i=1;i<m;i++)if(b[i].ave<=a[i+1])nx.add(i,1);
        for(int i=1;i<=m;i++){
            for(int o=b[i].l;o<=b[i].r;o++){
                int now=b[i].v[o-b[i].l];
                double av=(b[i].sum-now)*1.0/(b[i].k-1);
                int ll=1,rr=m,mid,res=m+1;
                while(ll<=rr){
                    mid=(ll+rr)>>1;
                    if(b[mid].ave<=av)res=mid,rr=mid-1;
                    else ll=mid+1;
                }
                if(res<i){
                    ans[o]=((st.ask(res-1)+nx.ask(i-1)-nx.ask(res-1)+st.ask(m)-st.ask(i)+(a[res]>=av))==m);
                }
                else if(res>i){
                    ans[o]=((st.ask(i-1)+pe.ask(res-1)-pe.ask(i)+st.ask(m)-st.ask(res-1)+(a[res-1]>=av))==m);
                }
                else ans[o]=((st.ask(i-1)+st.ask(m)-st.ask(i)+(av<=a[i]))==m);
            }
        }
        for(int i=1;i<cnt;i++)printf("%d",ans[i]);
        puts("");
    }
    return  0;
}