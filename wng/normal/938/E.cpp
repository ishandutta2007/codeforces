#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


pair<int, pair<int, int> > bezout(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

int main(){
    ll res=0;
    int n;
    scanf("%d",&n);
    int t[1000001]={0};
    int mod=1E9+7;
    ll fn=1;
    for (int i=0;i<n;i++) {
        scanf("%d",&t[i]);
        fn*=i+1,
        fn%=mod;
    }
    sort(t,t+n,greater<int>());
    int a=0;
    int b=0;
    while (a<n)
    {
        while (b<n and t[a]==t[b]) {b+=1;}
        if (a>0)
        {
            //il y a b-a elements t[a], qui ont au global (b-a)/(b) chances d'apparaitre
            //donc il y a (a-b)*fact(n)/(n-a) occurences de t[a]
            ll toadd=t[a];
            toadd*=(b-a);
            toadd%=mod;
           // cout<<"inverse "<<b<<" : "<<inv[b]<<" "<<(b*inv[b])%mod<<endl;
            toadd*=(bezout(b,mod).second.first+mod)%mod;
            toadd%=mod;
            res+=toadd;
        }
        a=b;
    }
    res%=mod;
    res*=fn;
    res%=mod;
    printf("%lld\n",res);
}