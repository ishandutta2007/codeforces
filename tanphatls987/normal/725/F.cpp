#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second

const int N=1e5+10;
int n;
ii a[N][2];

vector <int> b;

int main(){
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1;j++) scanf("%d%d",&a[i][j].X,&a[i][j].Y);
        if (a[i][0].X+a[i][0].Y>a[i][1].X+a[i][1].Y){
            for(int j=0;j<=1;j++){
                ii cur=a[i][j];
                ans+=cur.X-cur.Y;
                b.push_back(cur.X+cur.Y);
            }
        }else{
            if (a[i][0].X>a[i][1].Y){
                ii cur=ii(a[i][0].X-a[i][1].Y,a[i][1].Y-a[i][0].X);
                ans+=cur.X-cur.Y;
                b.push_back(cur.X+cur.Y);
            }
            if (a[i][0].Y>a[i][1].X){
                ii cur=ii(a[i][1].X-a[i][0].Y,a[i][0].Y-a[i][1].X);
                ans+=cur.X-cur.Y;
                b.push_back(cur.X+cur.Y);
            }
        }
//        cout<<ans<<'\n';
    }
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<b.size();i++)
        ans+=(i&1)?-b[i]:b[i];
    cout<<ans/2;
}