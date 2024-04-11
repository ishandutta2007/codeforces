#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s=="0"){cout<<0;return 0;}
    int cnt1=0,cnt0=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt0++;
        else cnt1++;
    }
    cout<<1;
    for(int i=0;i<cnt0;i++)cout<<0;
}