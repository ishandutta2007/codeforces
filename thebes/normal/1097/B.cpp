#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 20;
int N, arr[MN], i, ans;
int rec(int n,int deg){
    if(n==N){
        if(deg%360==0) ans=1;
    }
    else{
        rec(n+1, deg+arr[n]);
        rec(n+1, deg-arr[n]);
    }
}
int main(){
    for(scanf("%d",&N),i=0;i<N;i++)
        scanf("%d",&arr[i]);
    rec(0,0);
    printf("%s\n",(ans)?"YES":"NO");
    return 0;
}