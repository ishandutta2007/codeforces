#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 1e5+9;
int n,a[N],b[19];
int pri[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
bool insert(int c){
    for(int i=0;i<19;i++)
        if(c&(1<<i)){
            if(!b[i]){b[i]=c;return 1;}
            c^=b[i];
        }
    return 0;
}

ll qpow(ll x,ll y){ll t=1;while(y){if(y&1) (t*=x)%=mod;y>>=1,(x*=x)%=mod;}return t;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int tim=0;
    for(int i=1;i<=n;i++){
        int c=0;
        for(int j=0;j<19;j++)
            while(a[i]%pri[j]==0){
                c^=(1<<j);
                a[i]/=pri[j];
            }
        if(!insert(c)) tim++;
    }
    printf("%lld\n",(qpow(2,tim)-1+mod)%mod);
    return 0;
}
/*
a_ia_i10
0
a_i137019

x
2^{}-1
*/