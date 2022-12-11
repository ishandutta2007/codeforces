#include<bits/stdc++.h>
using namespace std;
const int N=5e4+1000;
long long vl[N],ans[400][N],val[N];
int tag[N],m,n,q,minum[N],L[N],R[N],bel[N],blk=250,a[N],b[N];
vector<int>fac[N];
vector<long long>pri;
long long divi[N];
void solve_prime(long long mx){
    divi[1]=1;
    for(long long i=2;i<=mx;i++){
        if(!divi[i])pri.push_back(i),divi[i]=i;
        for(long long o:pri){
            if(o>divi[i]||o*i>mx)break;
            divi[i*o]=o;
        }
    }
}
int gcd(int a, int b) {
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int z = min(az, bz);
    b >>= bz;
    while (a) {
        a >>= az;
        int diff = a - b;
        az = __builtin_ctz(diff);
        b = min(a, b), a = abs(diff);
    }
    return b << z;
}
void cot(int x){
    if(!tag[x])return;
    for(int i=L[x];i<=R[x];i++)a[i]=tag[x];
    tag[x]=0;
    val[x]=1e18;
    for(int i=L[x];i<=R[x];i++){
        long long zm=gcd(a[i],b[i]);
        vl[i]=a[i]/zm*b[i]/zm;
        val[x]=min(val[x],vl[i]);
    }
}
void rec(int x){
    val[x]=1e18;
    for(int i=L[x];i<=R[x];i++)val[x]=min(val[x],vl[i]);
}
int main(){
    solve_prime(5e4+1);
    for(int i=1;i<=5e4;i++){
        for(int o=1;o*o<=i;o++){
            if(i%o==0)fac[i].push_back(o),fac[i].push_back(i/o);
        }
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1,ct=1;i<=n;i+=blk,ct++){
        for(int o=i;o<i+blk;o++){
            bel[o]=ct;
        }
        L[ct]=i,R[ct]=min(i+blk-1,n);
        m=ct;
    }
    memset(ans,63,sizeof ans);
    for(int i=1;i<=m;i++){
        for(int o=1;o<=5e4;o++)minum[o]=1e9;
        for(int o=L[i];o<=R[i];o++){
            for(auto it:fac[b[o]])minum[it]=min(minum[it],b[o]);
        }
        for(int o=1;o<=5e4;o++)if(minum[o]<=5e4)ans[i][o]=minum[o]/o;
        for(int o=1;o<=5e4;o++){
            for(int k:pri){
                if(o*k>5e4)break;
                ans[i][o*k]=min(ans[i][o*k],ans[i][o]*k);
            }
        }
    }
    memset(val,63,sizeof val);
    for(int i=1;i<=n;i++){
        long long zm=gcd(a[i],b[i]);
        vl[i]=a[i]/zm*b[i]/zm;
        val[bel[i]]=min(val[bel[i]],vl[i]);
    }
    while(q--){
        int tp;
        scanf("%d",&tp);
        if(tp==1){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            if(bel[l]==bel[r]){
                cot(bel[l]);
                for(int i=l;i<=r;i++){
                    a[i]=x;
                    long long zm=gcd(a[i],b[i]);
                    vl[i]=a[i]/zm*b[i]/zm;
                }
                rec(bel[l]);
            }
            else{
                cot(bel[l]);
                cot(bel[r]);
                for(int i=bel[l]+1;i<bel[r];i++){
                    val[i]=ans[i][x];
                    tag[i]=x;
                }
                for(int i=l;i<=R[bel[l]];i++){
                    a[i]=x;
                    long long zm=gcd(a[i],b[i]);
                    vl[i]=a[i]/zm*b[i]/zm;
                }
                for(int i=L[bel[r]];i<=r;i++){
                    a[i]=x;
                    long long zm=gcd(a[i],b[i]);
                    vl[i]=a[i]/zm*b[i]/zm;
                }
                rec(bel[l]);
                rec(bel[r]);
            }
        }
        else{
            int l,r;
            long long res=1e18;
            scanf("%d%d",&l,&r);
            if(bel[l]==bel[r]){
                cot(bel[l]);
                rec(bel[l]);
                for(int i=l;i<=r;i++)res=min(res,vl[i]);
            }
            else{
                cot(bel[l]);
                cot(bel[r]);
                rec(bel[l]);
                rec(bel[r]);
                for(int i=bel[l]+1;i<bel[r];i++)res=min(res,val[i]);
                for(int i=l;i<=R[bel[l]];i++)res=min(res,vl[i]);
                for(int i=L[bel[r]];i<=r;i++)res=min(res,vl[i]);
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}