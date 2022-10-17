
#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x>3) puts("YES");
        else if(x==1)
        {
            if(y==1) puts("YES");
            else puts("NO");
        }
        else if(x==2 || x==3)
        {
            if(y<=3) puts("YES");
            else puts("NO");
        }
    }
}