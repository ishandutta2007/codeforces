#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(it,a) for (it=a.begin();it!=a.end();++it)
#define sum(x1,y1,x2,y2) (s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1])
#define N 1005
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
#define INF 0x7fffffff
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
int n,m,s[N][N],ans=INF,flag,px,py,tmp,wx,wy;char mat[N][N];
int work(int x,int y,int wx,int wy){
    if(sum(x,y+1,x+wx-1,y+wy)==wx*wy)return wx+work(x,y+1,wx,wy);
    if(sum(x+1,y,x+wx,y+wy-1)==wx*wy)return wy+work(x+1,y,wx,wy);
    return 0;
}
int main() {
    read(n,m);rep(i,1,n)scanf("%s",mat[i]+1);
    rep(i,1,n+1) rep(j,1,m+1) {
        if(mat[i][j]=='X')
        {
            if(!flag){flag=1;px=i;py=j;}
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+1;
        }
        else s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    }
    for(tmp=px;mat[tmp][py]=='X';tmp++);wx=tmp-px;
    for(int i=py;mat[px][i]=='X';i++)if(sum(px,py,px+wx-1,i)==wx*(i-py+1)&&work(px,py,wx,i-py+1)+wx*(i-py+1)==s[n][m])
    ans=min(ans,wx*(i-py+1));
    for(tmp=py;mat[px][tmp]=='X';tmp++);wy=tmp-py;
    for(int i=px;mat[i][py]=='X';i++)if(sum(px,py,i,py+wy-1)==(i-px+1)*wy&&work(px,py,i-px+1,wy)+(i-px+1)*wy==s[n][m])
    ans=min(ans,(i-px+1)*wy);if(ans<=n*m)cout<<ans<<endl;else puts("-1");
    return 0;
}