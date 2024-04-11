#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    set<int> curr;
    map<int,int> freq;
    int l = 0;
    int r = 0;
    pair<int,int> ans;
    while(r<n){
        while(r<n){
            curr.insert(a[r]);
            ++freq[a[r]];
            ++r;
            if(curr.size()>k){
                --freq[a[l]];
                if(freq[a[l]]==0) curr.erase(a[l]);
                ++l;
                if(r-l>ans.second-ans.first && curr.size()<=k){
                    ans = {l,r-1};
                }
                break;
            }
            else{
                if(r-l>ans.second-ans.first){
                    ans = {l,r-1};
                }
            }
        }
    }
    cout << ans.first+1 <<" " << ans.second+1 << endl;
    
}