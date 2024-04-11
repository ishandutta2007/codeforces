#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,(int)mod-2);}
const int N=3e5+5;
int F[N],I[N];
int binom(int n, int k){ return mul(F[n],mul(I[k],I[n-k]));}
void calc()
{
	F[0]=1;
	for(int i=1;i<N;i++) F[i]=mul(F[i-1],i);
	I[N-1]=inv(F[N-1]);
	for(int i=N-2;~i;i--) I[i]=mul(I[i+1],i+1);
}
int main(){
    calc();
    int n,k;scanf("%i %i",&n,&k);
    vector<pair<int,int>> e;
    for(int i=0;i<n;i++){
        int l,r;scanf("%i %i",&l,&r);
        e.pb({l,0});
        e.pb({r,1});
    }
    sort(e.begin(),e.end());
    int bal=0,ans=0;
    for(auto c:e){
        if(c.second==0){
            bal++;
            if(bal>=k)ckadd(ans,binom(bal-1,k-1));
        }else bal--;
    }
    printf("%i",ans);
    return 0;
}