#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
#define X first
#define Y second

const int inf=1e9+10;
const int N=1e3+10;
const double eps=1e-12;

int a[N][2];
int n,wei;


bool check(double fuel){
        for(int i=1;i<=n;i++){
                fuel-=(fuel+wei)/a[i][0];
                if (fuel<eps) return 0;
                fuel-=(fuel+wei)/a[i+1][1];
                if (fuel<eps) return 0;
        }
        return 1;
        
}
int main(){
        cin>>n>>wei;
        for(int i=1;i<=n;i++) cin>>a[i][0];
        for(int i=1;i<=n;i++) cin>>a[i][1];
        a[n+1][1]=a[1][1];
        double L=0,R=2*inf;
        for(int i=1;i<=1000;i++){
                double mid=(L+R)/2;
                if (check(mid)) R=mid;
                else L=mid;
        }
        if (L>inf) cout<<"-1";
        else printf("%.12f",L);
}