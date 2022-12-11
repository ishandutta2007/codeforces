#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int v1=count(s.begin(),s.end(),'A'),v2=n-v1;
    if (v1==v2) printf( "Friendship");
    else if (v1>v2) printf("Anton");
    else printf("Danik");
}