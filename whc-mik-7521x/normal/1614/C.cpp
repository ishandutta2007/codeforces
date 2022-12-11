#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,m,t;
int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
    return r;
}

void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[21]; int sz = 0;
    if(!x) pc(48);
    else {
        while(x) c[++sz] = x % 10, x /= 10;
        while(sz) pc(c[sz--] + 48);
    } pc(10);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    t=read();
    while(t--){
        n=read();m=read();
        long long ans=0;
        for(int i=1;i<=m;i++){
            read(),read();ans|=read();
        }
        for(int i=1;i<n;i++)ans*=2,ans%=mod;
        wrt(ans%mod);
    }
    return  0;
}