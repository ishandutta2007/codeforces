#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
const int MN = 60006;
typedef pair<double,double> pii;
pii cmp(pii i,pii j){return make_pair(max(i.first,j.first),min(i.second,j.second));}
int n, i, j, x[MN], v[MN];
double lo, hi;
bool check(double t){
        pii wew(-1, 1e9+7);
        for(int i=1;i<=n;i++)
                wew = cmp(wew, make_pair(x[i]-v[i]*t,x[i]+v[i]*t));
        return wew.first<=wew.second;
}
int main(){
        for(scanf("%d",&n),i=1;i<=n;i++)
                scanf("%d",&x[i]);
        for(i=1;i<=n;i++)
                scanf("%d",&v[i]);
        lo=0; hi=1e9;
        while(lo+eps<hi){
                double m=(lo+hi)/2;
                if(check(m)) hi=m;
                else lo=m+eps;
        }
        printf("%.7lf\n",lo);
        return 0;
}