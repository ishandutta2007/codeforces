#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    vector<pair<int,int>> ans;
    for(int i=0;i<n-2;i++){
        int x=0;
        for(int j=0;j<=30;j++)if(((1<<j)&a[i])!=0)x=j;
        long long k=(1<<(x+1));
        long long sum=a[i+1];
        for(int j=i+2;j<n;j++){
            if((a[i]^a[j])==sum)ans.push_back({i,j});
            sum+=a[j];
            if(sum>k)break;
        }
    }
    reverse(a,a+n);
    for(int i=0;i<n-2;i++){
        int x=0;
        for(int j=0;j<=30;j++)if(((1<<j)&a[i])!=0)x=j;
        long long k=(1<<(x+1));
        long long sum=a[i+1];
        for(int j=i+2;j<n;j++){
            if((a[i]^a[j])==sum)ans.push_back({n-j-1,n-i-1});
            sum+=a[j];
            if(sum>k)break;
        }
    }
    sort(ans.begin(),ans.end());
    int cnt=(int)ans.size()>0;
    for(int i=1;i<(int)ans.size();i++)if(ans[i]!=ans[i-1])cnt++;
    printf("%i",cnt);
    return 0;
}