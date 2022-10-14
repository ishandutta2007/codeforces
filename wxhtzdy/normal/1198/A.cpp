#include <bits/stdc++.h>
using namespace std;
const int N=400050;
int n,m,a[N];
int main(){
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    int k=8*m/n;
    if(k>30)return 0*printf("0");
    int K=pow(2,k),cnt=0,l=0,r=0,ans=0;
    map<int,int> mp;
    while(r<n){
        mp[a[r]]++;
        if(mp[a[r]]==1)cnt++;
        while(cnt>K){
            if(mp[a[l]]==1)cnt--;
            mp[a[l]]--,l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    printf("%i",n-ans);
    return 0;
}