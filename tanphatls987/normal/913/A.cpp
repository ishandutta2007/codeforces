#include <bits/stdc++.h>

using namespace std;

int main(){
        int n,m;
        cin>>n>>m;
        cout<<((n<=30)?(m%(1<<n)):m);
}