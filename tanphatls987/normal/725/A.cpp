#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int main(){
    cin>>n>>s;
    int st=0,en=0;
    while (st<n&&s[st]=='<') st++;
    while (en<n&&s[n-en-1]=='>') en++;
    cout<<st+en;
}