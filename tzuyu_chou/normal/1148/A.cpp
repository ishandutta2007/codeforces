#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    long long a,b,c;
    cin >> a >> b >> c;
    b=min(b,a+1);
    a=min(a,b+1);
    cout << 2*c+a+b << endl;
}