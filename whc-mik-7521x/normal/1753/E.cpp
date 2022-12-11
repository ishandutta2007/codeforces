#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long n,b,p,m,ct,lct,ch[N],L[N],R[N],vl[N];
vector<vector<long long>>vec,sum;
vector<long long>mul;
long long find(long long num,long long val){
    if(!vec[num].size())return -1;
    long long l=0,r=(int)vec[num].size()-1,ans=-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(vec[num][mid]*(L[num]-1)*R[num]>=val)ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
bool check(long long mid,long long rb){
    for(long long i=1;i<lct;i++){
        rb-=1ll*p*(find(i,mid)+1);
    }
    return rb>=0;
}
long long solve(){
    long long res=0,rb=b,rmul=1;
    for(long long i=0;i<ct;i++)vl[i]=ch[i]?(rmul*=mul[i],1):mul[i];
    L[0]=1;R[lct-1]=rmul;
    for(long long i=1;i<lct;i++)L[i]=L[i-1]*vl[i-1];
    for(long long i=lct-2;i>=0;i--)R[i]=R[i+1]*vl[i];
    for(long long i=0;i<lct;i++)if(vec[i].size())res+=sum[i].back()*R[i];
    long long l=0,r=2e18+1,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid,rb))r=mid-1,ans=mid;
        else l=mid+1;
    }
    for(long long i=1;i<lct;i++){
        long long now=find(i,ans)+1;
        if(now&&vec[i].size())res+=sum[i][now-1]*(L[i]-1)*(R[i]);
        assert(now>=0);
        rb-=now*p;
    }
    assert(rb>=0);
    res+=max(ans-1,0ll)*((long long)(rb/p));
    return res;
}
long long dfs(long long x,long long mi){
    if(b<0)return -1e18;
    if(x==-1){
        return solve();
    }
    long long res=0;
    ch[x]=1;
    b-=m;
    res=max(res,dfs(x-1,min(mi,mul[x])));
    b+=m;
    if(mul[x]<mi){
        ch[x]=0;
        res=max(res,dfs(x-1,mi));
    }
    return res;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&b,&p,&m);
    vector<long long>now={1};
    for(long long i=1;i<=n;i++){
        char s[10];
        long long a;
        scanf("%s%lld",s,&a);
        if(s[0]=='+')now.push_back(a);
        else{
            if(a!=1){
                vec.push_back(now);
                mul.push_back(a);
                now.clear();
            }
        }
    }
    vec.push_back(now);
    ct=mul.size();
    lct=vec.size();
    assert(lct-ct==1);
    for(auto &it:vec){
        stable_sort(it.begin(),it.end());
        reverse(it.begin(),it.end());
        vector<long long>kk=it;
        for(int i=1;i<(int)kk.size();i++)kk[i]+=kk[i-1];
        sum.push_back(kk);
    }
    printf("%lld",dfs(ct-1,INT_MAX));
    return 0;
}