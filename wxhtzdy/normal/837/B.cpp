#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    char a[n+1][m+1];
    for(int i=0;i<n;i++)scanf("%s",&a[i]);
    bool ok=0;
    for(int i=0;i<n;i++){
        if(n%3==0&&n/3==i+1){
            map<char,int> mp;
            map<char,int> my_cnt;
            bool all_same=1;
            for(int j=0;j<=i;j++)for(int k=0;k<m;k++)mp[a[j][k]]++;
            int cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            mp.clear();
            for(int j=i+1;j<2*(i+1);j++)for(int k=0;k<m;k++)mp[a[j][k]]++;
            cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            mp.clear();
            for(int j=2*(i+1);j<n;j++)for(int k=0;k<m;k++)mp[a[j][k]]++;
            cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            for(char c:{'R','B','G'})if(my_cnt[c]!=1)all_same=0;
            if(all_same)ok=1;
        }
    }
    for(int i=0;i<m;i++){
        if(m%3==0&&m/3==i+1){
            map<char,int> mp;
            map<char,int> my_cnt;
            bool all_same=1;
            for(int j=0;j<=i;j++)for(int k=0;k<n;k++)mp[a[k][j]]++;
            int cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            mp.clear();
            for(int j=i+1;j<2*(i+1);j++)for(int k=0;k<n;k++)mp[a[k][j]]++;
            cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            mp.clear();
            for(int j=2*(i+1);j<m;j++)for(int k=0;k<n;k++)mp[a[k][j]]++;
            cnt=0;
            for(char c:{'R','B','G'}){
                cnt+=mp[c]>0;
                if(mp[c]>0)my_cnt[c]++;
            }
            if(cnt!=1)all_same=0;
            for(char c:{'R','B','G'})if(my_cnt[c]!=1)all_same=0;
            if(all_same)ok=1;
        }
    }
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}