#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,A,cf,cm;
ll m;
int a[100001];
set<pair<int,int>> pref;
ll p[100001];
bool work(int x,int r,ll s){
    auto it = pref.upper_bound({x,n+1});
    if(it==pref.begin()) return true;
    --it;
    int idx = (*it).second;
    ll cost = 0;
    if(idx>r-1){
        if(r>=1)
            cost = 1LL*(r-1+1)*x-p[r-1];
    }
    else
        cost = 1LL*(idx+1)*x-p[idx];
    return cost<=s;
}
int binarySearch(int lo,int hi, int r,ll s){
    int mid = (lo+hi)/2;
    if(work(mid,r,s)){
        if(mid+1>hi || !work(mid+1,r,s))
            return mid;
        return binarySearch(mid+1,hi,r,s);
    }
    return binarySearch(lo,mid-1,r,s);
    
}
int main(){
    scanf("%d%d%d%d%lld",&n,&A,&cf,&cm,&m);
    pair<int,int> b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        b[i] = {a[i],i};
    }
    ll best = 0;
    sort(a,a+n);
    p[0] = a[0];
    for(int i=1;i<n;i++) p[i] = a[i]+p[i-1];
    for(int i=0;i<n;i++){
        pref.insert({a[i],i});
    }
    ll currcost = 0;
    int currmin = binarySearch(0,A,n,m-currcost);
    best = max(best,cm*1LL*currmin);
    int num = n;
    for(int i=n-1;i>=0;i--){
        currcost+=1LL*(A-a[i]);
        //0 i
        if(currcost>m) continue;
        currmin = binarySearch(0,A,i,m-currcost);
        if(cm*1LL*currmin+cf*1LL*(n-i)>best){
            best = cm*1LL*currmin+cf*1LL*(n-i);
            num = i;
        }
    }
    cout << best << endl;
    sort(b,b+n);
    currcost = 0;
    for(int i=num;i<n;i++) currcost+=A-a[i];
    currmin = binarySearch(0,A,num,m-currcost);
    for(int i=0;i<num;i++){
        if(b[i].first<currmin) b[i].first = currmin;
    }
    for(int i=num;i<n;i++)
        b[i].first = A;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
        ans.push_back({b[i].second,b[i].first});
    sort(ans.begin(),ans.end());
    for(auto &it : ans){
        cout << it.second << " ";
    }

}