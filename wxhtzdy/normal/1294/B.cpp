#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++)scanf("%i %i",&p[i].first,&p[i].second);
        sort(p.begin(),p.end());
        bool ok=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(p[i].first>p[j].first&&p[i].second<p[j].second)ok=0;
            }
        }
        if(!ok){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int x=0,y=0;
        for(int i=0;i<n;i++){
            while(x<p[i].first)x++,printf("R");
            while(y<p[i].second)y++,printf("U");
        }
        printf("\n");
    }
}