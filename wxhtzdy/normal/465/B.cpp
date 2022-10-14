#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    vector<int>pos;
    for(int i=0;i<n;i++)if(a[i]==1)pos.pb(i);
    int res=(int)pos.size()>0;
    for(int i=1;i<(int)pos.size();i++)res+=min(2,pos[i]-pos[i-1]);
    printf("%i",res);
    return 0;
}