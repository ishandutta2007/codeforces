#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    scanf("%i",&n);
    vector<int> all;
    for(int i=2;i<=n;i+=2)all.pb(i);
    for(int i=1;i<=n;i+=2)all.pb(i);
    for(int i=2;i<=n;i+=2)all.pb(i);
    printf("%i\n",(int)all.size());
    for(int p:all)printf("%i ",p);
    return 0;
}