#include<bits/stdc++.h>
using namespace std;

int t;
long long n,g,b,c,p,gds,bds;

long long ck(long long u){
    return u/(g+b)*g+min(u%(g+b),g);
}

long long ms(long long l,long long r){
    if (l==r) return l;
    long long md=(l+r)>>1;
    if (ck(md)>=(n+1)/2) return ms(l,md);
    else return ms(md+1,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>g>>b;
        cout<<ms(n,1e18)<<endl;
    }
    return 0;
}