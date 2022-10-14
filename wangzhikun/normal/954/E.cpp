#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n,t;
double st = 0,sa = 0;

struct water{
    ll a,t,tom;//ttt
} wts[400020];
bool cmp(water l,water r){return l.t<r.t;}
int main() {
    cin>>n>>t;
    for(int i=0;i<n;i++)cin>>wts[i].a;
    for(int i=0;i<n;i++)cin>>wts[i].t;
    for(int i=0;i<n;i++){
        wts[i].tom = wts[i].t*wts[i].a;
        st+=wts[i].tom;
        sa+=wts[i].a;
    }
    sort(wts,wts+n,cmp);
    if(wts[0].t>t || wts[n-1].t < t){
        cout<<0<<endl;
        return 0;
    }
    
    
    for(int i=n-1;i>=0;i--){
        if((st/sa)>t && wts[i].t > t){
            if((st-wts[i].tom)/(sa-wts[i].a)>t){
                sa-=wts[i].a;
                st-=wts[i].tom;
                continue;
            }
            double k = 1;
            if(wts[i].tom!=t*wts[i].a) k=(st-t*sa)/(wts[i].tom-t*wts[i].a);
            k = min(max(k,0.0),1.0);
            sa -=k*wts[i].a;
            break;
        }else break;
    }
    
    for(int i=0;i<n;i++){
        if((st/sa)<t && wts[i].t < t){
            if((st-wts[i].tom)/(sa-wts[i].a)<t){
                sa-=wts[i].a;
                st-=wts[i].tom;
                continue;
            }
            double k = 1;
            if(wts[i].tom!=t*wts[i].a) k=(st-t*sa)/(wts[i].tom-t*wts[i].a);
            k = min(max(k,0.0),1.0);
            sa -=k*wts[i].a;
            break;
        }else break;
    }
    printf("%.16f",sa);
    return 0;
}