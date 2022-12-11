#include <bits/stdc++.h>

using namespace std;

int main(){
    int xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;

    int ans=max(abs(xb-xa),1)+max(abs(yb-ya),1)+2;
    cout<<2*ans;
}