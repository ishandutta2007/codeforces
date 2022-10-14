#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int l=m/2,r=m/2;
    if(m%2==0)r++;
    else l++,r++;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.pb(l);
        if(i>=n) break;
        if(l!=r) v.pb(r);
        --l,++r;
        if(l==0||r>m){
            l=m/2,r=m/2;
            if(m%2==0)r++;
            else l++,r++;
        }
    }
    for(int i=0;i<n;i++)printf("%i\n",v[i]);
    return 0;
}