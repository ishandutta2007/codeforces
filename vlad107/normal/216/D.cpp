#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 200500

using namespace std;

int n,ans=0,kg[N+5],pi,ne,x,s[2][N+5];
vector<int> a[N+5];

void add(int t,int x){
    while (x<N){
        s[t][x]++;
        x=(x|(x-1))+1;
    }
}

int fsum(int t,int x){
    int res=0;
    while (x){
        res+=s[t][x];
        x&=(x-1);
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&kg[i]);
        a[i].clear();
        for (int j=0;j<kg[i];j++){
            scanf("%d",&x);
            a[i].push_back(x);
        }
    }
    for (int i=0;i<n;i++){
        pi=(i-1+n)%n;
        ne=(i+1)%n;
        for (int j=0;j<N;j++){
            s[0][j]=0;s[1][j]=0;
        }
        for (int j=0;j<a[pi].size();j++)add(0,a[pi][j]);
        for (int j=0;j<a[ne].size();j++)add(1,a[ne][j]);
        sort(a[i].begin(),a[i].end());
        for (int j=0;j<a[i].size()-1;j++)
            if (fsum(0,a[i][j+1])-fsum(0,a[i][j])!=fsum(1,a[i][j+1])-fsum(1,a[i][j]))
                ans++;
    }
    printf("%d",ans);
}