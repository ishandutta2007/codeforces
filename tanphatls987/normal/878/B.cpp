#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

typedef long long ll;

int n,m,k;
int f[N];


int a[N],b[N];
ll process(int* a,int n,int m,int *res,int &n2){
    n2=0;

    ll out=0;
    for(int i=1;i<=n;i++){
        res[++n2]=a[i];
        if (res[n2]==res[n2-1]) f[n2]=f[n2-1]+1;
        else f[n2]=1;
        if (f[n2]>=k){
            out+=1LL*k*m;
            n2-=k;
        }
    }
    return out;
}
vector <int> pre,suf;
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll total=1LL*n*m;
    ll out=process(a,n,m,b,n);
    int L=1,R=n;
    while (L<=R&&b[L]==b[R]){
//            cout<<L<<" "<<R<<'\n';
        int n1=0;
        while (L+n1<=R&&b[L+n1]==b[L]) n1++;
        if (n1==R-L+1){
            ll all=1LL*(R-L+1)*m;
            ll rem=all%k;
            out+=all-rem;
            if (!rem){
                int remn=0;
                for(auto x:pre) a[++remn]=x;
                for(int i=1;i<=suf.size();i++) a[++remn]=suf[suf.size()-i];
                out+=process(a,remn,1,b,n);
            }
            break;
        }
        int n2=0;
        while (b[R-n2]==b[R]) n2++;
//    cout<<n1+n2<<'\n';
        if (n1+n2<k) break;
        out+=1LL*k*(m-1);
        for(int i=1;i<=n1;i++) pre.push_back(a[L]);
        for(int i=1;i<=k-n1;i++) suf.push_back(a[L]);
        L+=n1;
        R-=k-n1;
    }
    cout<<total-out;
}