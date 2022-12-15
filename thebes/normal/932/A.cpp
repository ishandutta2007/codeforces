#include <bits/stdc++.h>
using namespace std;

string a;

int main(){
    cin >> a;
    for(int i=a.size()-2;i>=0;i--)
        a.push_back(a[i]);
    printf("%s\n",a.c_str());
    return 0;
}