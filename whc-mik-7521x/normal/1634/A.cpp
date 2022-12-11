#include<bits/stdc++.h>
using namespace std;
int n,k;
int solve1(int x){
    return x?1:1;
}
int solve2(int x){
    return x?2:1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        string ss=s;
        reverse(s.begin(),s.end());
        if(s==ss)cout<<solve1(k)<<endl;
        else cout<<solve2(k)<<endl;
    }    
    return  0;
}