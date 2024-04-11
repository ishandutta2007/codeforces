#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
ll f(int n){return (ll)n*(n-1)/2;}
ll g(int x,int y){return (ll)x*1e9+y+100;}
struct tacka{
    int n,x[N],y[N];
    void ulaz(){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i %i",&x[i],&y[i]);
    }
    ll solve(){
        map<int,int> mx,my;
        map<ll,int> s;
        for(int i=1;i<=n;i++)mx[x[i]]++,my[y[i]]++,s[g(x[i],y[i])]++;
        ll ans=0;
        for(int i=1;i<=n;i++)ans+=f(mx[x[i]]),mx[x[i]]=0;
        for(int i=1;i<=n;i++)ans+=f(my[y[i]]),my[y[i]]=0;
        for(int i=1;i<=n;i++)ans-=f(s[g(x[i],y[i])]),s[g(x[i],y[i])]=0;
        return ans;
    }
    void izlaz(){
        printf("%lld",solve());
    }
}C;
int main(){
    C.ulaz();
    C.izlaz();
    return 0;
}