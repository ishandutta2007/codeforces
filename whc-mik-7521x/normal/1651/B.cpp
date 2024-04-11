#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int t;
int main(){
    scanf("%d",&t);
    vector<int>v;
    for(long long i=1;i<=1e9;i*=3){
        v.push_back(i);
    }
    int now=v.size();
    while(t--){
        int n;
        scanf("%d",&n);
        if(n>now)puts("NO");
        else{
            puts("YES");
            for(int i=0;i<n;i++)printf("%d ",v[i]);
            puts("");
        }
    }
    return  0;
}