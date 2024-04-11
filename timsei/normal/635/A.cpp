#include<bits/stdc++.h>
using namespace std;

const int N = 21;

int M[N][N] , n, r ,k ,c;

int count(int p1,int q1,int p2,int q2) {
    int res = 0;
    for(int i = p1;i <= p2;i ++) {
        for(int j =q1;j <= q2;j ++) {
            res+=M[i][j];
        }
    }
    return res;
}

int main() {
    scanf("%d%d%d%d",&r,&c,&n,&k);
    for(int i = 1;i <= n;i ++) {
        int x , y;
        scanf("%d%d",&x,&y);
        M[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= r;i ++) {
        for(int j = 1;j <= c;j ++) {
            for(int p1 = i;p1 <= r;p1  ++) {
                for(int p2 = j;p2<= c;p2 ++) {
                    if(count(i,j,p1,p2) >=k) {
                        ans ++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}