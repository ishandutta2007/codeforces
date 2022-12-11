#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,r;
    cin>>k>>r;
    k%=10;
    int ans=1,cur=k;
    while (1){
        int val=cur%10;
        if (val==0||val==r) break;
        ans++;
        cur+=k;
    }
    cout<<ans;
}