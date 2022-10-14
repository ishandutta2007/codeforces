#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<(int)a.length();i++){
        if(a[i]<'a')a[i]+='a'-'A';
        if(b[i]<'a')b[i]+='a'-'A';
    }
    if(a==b)cout<<0;
    else{
        if(a<b)cout<<-1;
        else cout<<1;
    }
}