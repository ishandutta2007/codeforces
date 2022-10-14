#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        int pref[n][205];
        for(int i=0;i<n;i++)for(int j=0;j<205;j++){
            if(i==0)pref[i][j]=(a[i]==j);
            else pref[i][j]=pref[i-1][j]+(a[i]==j);
        }
        vector<int> pos[205];
        for(int i=0;i<n;i++)pos[a[i]].push_back(i);
        map<int,int> cnt;
        int ans=0;
        for(int i=0;i<n;i++){
            cnt[a[i]]++;
            //printf("mudja cnt: %i %i ",a[i],cnt[a[i]]);
            int x=cnt[a[i]],sz=(int)pos[a[i]].size();
            int y=pos[a[i]][sz-x];
            int r=pos[a[i]][x-1];
            if(y<r)continue;
            if(r==y){
                ans=max(ans,x*2-1);
                continue;
            }
            int tmp=x*2,mx=0;
            for(int j=0;j<205;j++){
                mx=max(mx,pref[y-1][j]-pref[r][j]);
            }
            ans=max(ans,tmp+mx);
            //printf("%i\n",tmp+mx);
        }
        printf("%i\n",ans);
    }
    return 0;
}