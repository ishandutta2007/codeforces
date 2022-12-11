#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;


int n,kx,ky,p[N];
int a[N][2];
char type[N];

bool comp(int x,int y){
    return max(abs(a[x][0]),abs(a[x][1]))<max(abs(a[y][0]),abs(a[y][1]));
}


int totype(int dx,int dy){
    if (dx==0) return dy>0?1:3;
    if (dy==0) return dx>0?0:2;
    if (dx<0) return dy>0?4:7;
    return dy>0?5:6;
}
int mark[8];
string solve(){
    for(int j=1;j<=n;j++){
            int i=p[j];
        int dir=totype(a[i][0],a[i][1]);
//        cout<<i<<" "<<a[i][0]<<" "<<a[i][1]<<" "<<dir<<'\n';
        if (mark[dir]) continue;
        mark[dir]=1;
        if (dir<4&&type[i]=='B') continue;
        if (dir>=4&&type[i]=='R') continue;
        return "YES";
    }
    return "NO";
}
int main(){
    int kx,ky;
    cin>>n>>kx>>ky;
    for(int i=1;i<=n;i++){
        char ch;
    int x,y;
        cin>>ch>>x>>y;
        x-=kx;y-=ky;
        if (x!=0&&y!=0&&abs(x)!=abs(y)) {
            n--;i--;
            continue;
        }
        type[i]=ch;
        a[i][0]=x;a[i][1]=y;
    }
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,comp);
    cout<<solve();
}