#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[0]!='-'){cout<<s;return 0;}
    if((int)s.length()==2){cout<<0;return 0;}
    int n=(int)s.length();
    s[n-2]=min(s[n-2],s[n-1]);
    if(s[1]=='0'){cout<<0;return 0;}
    for(int i=0;i<n-1;i++)cout<<s[i];
}