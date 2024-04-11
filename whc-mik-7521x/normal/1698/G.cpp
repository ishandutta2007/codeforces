#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const int N=100,blk=1e6;
__gnu_pbds::gp_hash_table<long long,long long>mp;
struct node{
    int a[blk<<1],l,r;
    node(){memset(a,0,sizeof a);l=1e9;r=-1;}
    void modify(int x){
        a[x]=1;
        l=min(l,x);
        r=max(r,x);
    }
    void fix(){
        while(!a[r]&&r>=l)r--;
        while(!a[l]&&r>=l)l++;
    }
    void mod(const node &b){
        while(r>=b.r){
            l=min(l,r-b.r+b.l);
            for(int i=r,o=b.r;o>=b.l;o--,i--){
                a[i]^=b.a[o];
            }
            fix();
            if(r<l)return l=1e9,r=-1,void();
        }
    }
    long long val(){
        long long res=0;
        for(int i=0;i<=r;i++)if(a[i])res|=1ll<<i;
        return res;
    }
    void mul(const node &b){
        if(r<l)return;
        if(b.r<b.l)return r=-1,l=1e9,void();
        vector<int>vec(r+b.r-l-b.l+1);
        for(int i=l;i<=r;i++){
            for(int o=b.l;o<=b.r;o++){
                vec[i+o-l-b.l]^=a[i]&b.a[o];
            }
        }
        for(int i=l;i<=r;i++)a[i]=0;
        for(int i=l+b.l;i<=r+b.r;i++)a[i]=vec[i-l-b.l];
        l+=b.l;r+=b.r;
        return fix();
    }
}S,pw,ml,I1,I2;
char s[N];
int p[blk],n,l,r,ad;
long long val[blk<<1];
int main(){
    scanf("%s",s);
    I1.modify(0);I2.modify(0);
    n=strlen(s);
    for(int i=0;i<n;i++)p[i]=s[i]=='1';
    while(~n&&!p[n-1])n--;
    if(n==-1)return puts("-1"),0;
    while(!p[l])l++;
    ad=l+1;
    for(int i=l;i<n;i++)p[i-l]=p[i];
    n-=l;
    for(int i=0;i<n;i++)if(p[i])S.modify(i);
    pw.modify(blk);pw.mod(S);
    ml.modify(1);ml.mod(S);
    for(int i=0;i<=blk;i++){
        if(i){
            long long kk=I1.val();
            if(mp.find(kk)==mp.end())mp[kk]=i;
        }
        val[i]=I2.val();
        I1.mul(pw);I1.fix();I1.mod(S);
        I2.mul(ml);I2.fix();I2.mod(S);
    }
    long long ans=1e18;
    for(int i=0;i<blk;i++){
        if(mp.find(val[i])!=mp.end())ans=min(ans,mp[val[i]]*blk-i);
    }
    printf("%lld %lld",ad+0ll,ad+ans);
    return 0;
}