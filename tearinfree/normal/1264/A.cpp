#include <bits/stdc++.h>
using namespace std;

int n,arr[400000];
pair<int,int> solve(int *arr,int n,int g,int lim) {
    if(n==0) return {0, 0};
    int sum=0, ts[2]={0,}, f=0;
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && arr[i]==arr[j];j++);

        if(sum+j-i > lim) {
            if(!f || ts[f] <= g) return {0, 0};
            else return {ts[0], ts[1]};
        } 
        sum+=j-i;
        ts[f] += j-i;
        if(!f && ts[f] > g) f++;
    }
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",arr+i);

        int i;
        for(i=1;i<n && arr[i]==arr[i-1];i++);
        auto ans = solve(arr+i, n-i, i, n/2 - i);
        if(ans.first == 0) puts("0 0 0");
        else printf("%d %d %d\n",i,ans.first,ans.second);
    }
    return 0;
}