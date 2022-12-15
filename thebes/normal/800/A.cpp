#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
const int MN = 1e5+5;
pair<int,int> arr[MN];
int n, p, i;
double lo, hi, t;

bool check(double m){
    double tot = 0;
    for(int i=1;i<=n;i++)
        tot += max((double)0, (m*arr[i].first-arr[i].second)/(double)p);
    return tot <= m;
}

int main(){
    for(scanf("%d%d",&n,&p),i=1;i<=n;i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        t += arr[i].first;
    }
    if(t <= p) {
        printf("-1\n");
        return 0;
    }
    lo = 0; hi = 1e14+7;
    while(lo+eps < hi){
        double m=(lo+hi)/2;
        if(!check(m)) hi=m;
        else lo=m+eps;
    }
    lo -= eps;
    if(lo >= 1e14) printf("-1\n");
    else printf("%.7lf\n",lo);
    return 0;
}