#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int n; cin >> n;
    int s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int freq[4];
    for(int i=0;i<4;i++) freq[i] = 0;
    for(int i=0;i<n;i++){
        ++freq[--s[i]];
    }
    int ans = 0;
    int x = min(freq[0],freq[2]);
    freq[0]-=x; freq[2]-=x; ans+=x;
    ans+=freq[3];
    ans+=freq[2];
    freq[3] = 0;
    ans+=freq[1]/2;
    freq[1]%=2;
    if(freq[0] && freq[1]){
        ++ans;
        freq[0]-=2;
        if(freq[0]>0) ans+=(freq[0]+3)/4;
    }
    else if(freq[0] && !freq[1]){
        ans+=(freq[0]+3)/4;
    }
    else if(!freq[0] && freq[1]){
        ++ans;
    }
    cout << ans << endl;
    
}