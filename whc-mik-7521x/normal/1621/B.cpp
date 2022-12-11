#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n;
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        int mil=1e9,mxr=0;
        map<pair<int,int>,int>mp1;
        map<int,int>mpl;
        map<int,int>mpr;
        for(int i=1;i<=n;i++){
            int l,r,co;
            scanf("%lld%lld%lld",&l,&r,&co);
            if(!mp1[{l,r}])mp1[{l,r}]=co;
            else mp1[{l,r}]=min(mp1[{l,r}],co);
            if(!mpl[l])mpl[l]=co;
            else mpl[l]=min(mpl[l],co);
            if(!mpr[r])mpr[r]=co;
            else mpr[r]=min(mpr[r],co);
            mil=min(l,mil),mxr=max(r,mxr);
            printf("%lld\n",min(mp1[{mil,mxr}]?mp1[{mil,mxr}]:(int)1e18,mpl[mil]+mpr[mxr]));
        }
    }
    return  0;
}