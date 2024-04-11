#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

long long x;
int p;

long long get(int a,int b) {
    //p \equiv a mod (p-1), b mod p
    long long first = (a-b+p-1)%(p-1)*1LL*p+b;
    first%=p*1LL*(p-1);
    if(first<=0) first += p*1LL*(p-1);
    if(first>x) return 0;
    long long z = (x-first)*1LL/(p*1LL*(p-1));
    return z+1;
}

int main() {
    long long a,b;
    cin >> a >> b >> p >> x;
    int inv = 1;
    for(int i=1;i<p;i++) {
        if((a*1LL*i)%p==1) inv = i;
    }
    long long prod = b;
    long long ans = 0;
    for(int i=0;i<p-1;i++) {
        ans+=get(i,b);
        b = b*1LL*inv;
        b %= p;
        if(b<0) b+=p;
    }
    cout << ans << endl;
}