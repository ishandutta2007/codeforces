#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    map<int,int> cnt;
    pair<int,int> b;
    b.first=-1;
    b.second=1;
    for(int i=0;i<n;i++){
        scanf("%i",&a[i]),cnt[a[i]]++;
        if(cnt[a[i]]>b.first)b.first=cnt[a[i]],b.second=a[i];
    }
    printf("%i",b.second);
    return 0;
}