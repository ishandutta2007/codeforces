#include<bits/stdc++.h>
using namespace std;
int x;
int main(){
    scanf("%d",&x);
    int s=0;
    for(int i=1;i<=x;i++){
        int k;
        cin>>k;
        s+=k;
    }
    cout<<s;
    return  0;
}