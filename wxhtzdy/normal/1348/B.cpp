//RADIO HIT FM
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n,k;
        scanf("%i %i",&n,&k);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        sort(a,a+n);
        bool ok=1;
        vector<int> my;
        map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++)if(!mp[a[i]])cnt++,my.pb(a[i]),mp[a[i]]=1;
        if(cnt>k){printf("-1\n");continue;}
        int nxt=1;
        while((int)my.size()<k){
            if(!mp[nxt])my.pb(nxt);
            nxt++;
        }
        vector<int> all;
        for(int i=0;i<n;i++){
            for(auto c:my)all.push_back(c);
        }
        printf("%i\n",(int)all.size());
        for(auto c:all)printf("%i ",c);
        printf("\n");
    }
}