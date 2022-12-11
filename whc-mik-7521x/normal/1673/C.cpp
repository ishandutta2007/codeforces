#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10,mod=1e9+7;
vector<int>trans;
int dp[N][550];
void add(int &x,int y){
    x=x+y>=mod?x+y-mod:x+y;
}
bool pd(int x){
    vector<int>now,kk;
    while(x)now.push_back(x%10),x/=10;
    kk=now;
    reverse(kk.begin(),kk.end());
    return kk==now;
}
int main(){
    for(int i=1;i<N;i++)if(pd(i))trans.push_back(i);
    for(int o=0;o<(int)trans.size();o++)dp[0][o]=1;
    for(int i=1;i<N;i++){
        for(int o=0;o<(int)trans.size()&&trans[o]<=i;o++)add(dp[i][o],dp[i-trans[o]][o]);
        for(int o=1;o<(int)trans.size();o++)add(dp[i][o],dp[i][o-1]);
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x][trans.size()-1]);
    }
    return  0;
}