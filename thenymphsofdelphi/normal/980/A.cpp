#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int p=0,l=0;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]=='o')p++;
        else l++;
    }
    if(l==0||p==0||l%p==0)cout<<"YES";
    else cout<<"NO";
}