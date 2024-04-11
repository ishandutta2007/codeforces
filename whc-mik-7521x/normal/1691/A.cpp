#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],t;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int ct=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            ct+=x&1;
        }
        printf("%d\n",min(n-ct,ct));
    }
    return  0;
}