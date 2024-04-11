#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()

using namespace std;

typedef long long ll;

int n,m,k;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    if (min(m,k)>=n){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}