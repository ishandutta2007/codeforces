#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3],b[3];
    cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
    int x=0;
    for(int i=0;i<3;i++){
        if(a[i]!=b[i])  x++;
    }
    cout<<((x<3)?"YES":"NO");
}