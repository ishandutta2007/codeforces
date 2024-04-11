#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        reverse(a,a+n);
        for(int i=0;i<n;i++)scanf("%i",&b[i]);
        int cnt[3]={0,0,0};
        for(int i=0;i<n;i++)cnt[a[i]]++,cnt[b[i]]++;
        if(cnt[1]==cnt[2]){
            printf("0\n");
            continue;
        }
        map<int,int> hsh;
        int blue=0,red=0,ans=1e9;
        for(int i=0;i<n;i++){
            if(a[i]==1)blue++;
            else red++;
            if(hsh[blue-red]==0&&red!=blue)hsh[blue-red]=i+1;
            if(cnt[1]-blue==cnt[2]-red)ans=min(ans,i+1);
        }
        red=0,blue=0;
        for(int i=0;i<n;i++){
            if(b[i]==1)blue++;
            else red++;
            int need1=cnt[1]-blue,need2=cnt[2]-red;
            if(hsh[need1-need2]!=0||need1==need2)ans=min(ans,i+1+hsh[need1-need2]);
        }
        printf("%i\n",ans);
    }
    return 0;
}