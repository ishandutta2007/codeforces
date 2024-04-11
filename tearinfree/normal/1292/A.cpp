#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,-1,-1,1,1,1}, dx[]={-1,0,1,-1,0,1};
int arr[2][200001],n,m;

int main() {
    scanf("%d%d",&n,&m);

    int cnt=0;
    for(int i=0;i<m;i++) {
        int x,y;
        scanf("%d%d",&y,&x);
        y--; x--;
        arr[y][x] ^= 1;
        for(int k=0;k<6;k++) {
            int yy=y+dy[k],xx=x+dx[k];
            if(yy>=0 && yy<2 && xx>=0 && xx<n && arr[yy][xx]==1) {
                cnt += (arr[y][x]==1 ? 1 : -1);
            }
        }
        puts(cnt ? "No" : "Yes");
    }
    return 0;
}