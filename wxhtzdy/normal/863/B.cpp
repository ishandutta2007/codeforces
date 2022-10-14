#include <bits/stdc++.h>
using namespace std;
const int N=55;
int w[N];
int main(){
    int n;scanf("%i",&n);
    n*=2;
    for(int i=1;i<=n;i++)scanf("%i",&w[i]);
    int ans=1e9;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            if(x==y)continue;
            vector<int> b;
            for(int i=1;i<=n;i++)if(i!=x&&i!=y)b.push_back(w[i]);
            sort(b.begin(),b.end());
            int tmp=0;
            for(int i=1;i<(int)b.size();i+=2)tmp+=b[i]-b[i-1];
            ans=min(ans,tmp);
        }
    }
    printf("%i",ans);
    return 0;
}