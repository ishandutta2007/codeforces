#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        map<int,int> cnt;
        for(int i=0;i<n;i++)cnt[a[i]]++;
        int zer=0,one=0;
        for(auto c:cnt)zer++,one=max(one,c.second);
        printf("%i\n",max(min(zer-1,one),min(zer,one-1)));
    }
}