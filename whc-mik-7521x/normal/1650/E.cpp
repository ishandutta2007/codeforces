#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,d,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        multiset<int>s1,s2;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        stable_sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)s1.insert(a[i]-a[i-1]-1);
        for(int i=1;i<=n;i++)s2.insert(a[i]);
        int ans=0;
        for(int i=1;i<=n;i++){
            s1.erase(s1.find(a[i]-a[i-1]-1));
            if(i!=n)s1.erase(s1.find(a[i+1]-a[i]-1));
            if(i!=n)s1.insert(a[i+1]-a[i-1]-1);
            s2.erase(s2.find(a[i]));
            ans=max(ans,min(*s1.begin(),max(((*s1.rbegin())-1)>>1,d-(*s2.rbegin())-1)));
            s2.insert(a[i]);
            if(i!=n)s1.erase(s1.find(a[i+1]-a[i-1]-1));
            s1.insert(a[i]-a[i-1]-1);
            if(i!=n)s1.insert(a[i+1]-a[i]-1);
        }
        printf("%d\n",ans);
    }
    return  0;
}