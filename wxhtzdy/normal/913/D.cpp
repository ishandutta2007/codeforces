#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
int n,t,a[N],b[N],best=0;
vector<int> ans;
bool Can(int k){
    vector<pair<int,int>> all;
    for(int i=0;i<n;i++){
        if(a[i]>=k)all.pb({b[i],i+1});
    }
    sort(all.begin(),all.end());
    vector<int> v;
    int tmp=t,cnt=0;
    for(int i=0;i<(int)all.size();i++){
        if(tmp>=all[i].first&&cnt<k)tmp-=all[i].first,cnt++,v.pb(all[i].second);
    }
    if(cnt>=k){ans=v;return true;}
    else return false;
}
int main() {
    scanf("%i %i",&n,&t);
    for(int i=0;i<n;i++)scanf("%i %i",&a[i],&b[i]);
    int bot=0,top=n;
    while(bot<=top){
        int mid=(bot+top)/2;
        if(Can(mid))bot=mid+1,best=mid;
        else top=mid-1;
    }
    printf("%i\n",best);
    printf("%i\n",ans.size());
    for(int c:ans)printf("%i ",c);
    return 0;
}