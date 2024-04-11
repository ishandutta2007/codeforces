#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;

int g[5][5];
void boom()
{
    for(int i=1;i<=4;++i)
    {
        int ok = 1;
        for(int j=1;j<=4;++j)
        {
            if(!g[i][j]) {ok=0;break;}
        }
        if(ok)
        {
            for(int j=1;j<=4;++j) g[i][j]=0;
            return;
        }
    }
    for(int i=1;i<=4;++i)
    {
        int ok = 1;
        for(int j=1;j<=4;++j)
        {
            if(!g[j][i]) {ok=0;break;}
        }
        if(ok)
        {
            for(int j=1;j<=4;++j) g[j][i]=0;
            return;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='1')
        {
            int ok = 1, f = 0;
            for(int i=1;i<=4;++i)
            {
                for(int j=1;j<=3;++j)
                {
                    if(!g[i][j] && !g[i][j+1])
                    {
                        g[i][j] = g[i][j+1] = 1;
                        cout << i << " " << j << endl;
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
            boom();
        }
        else
        {
            int ok = 1, f = 0;
            for(int i=1;i<=4;++i)
            {
                for(int j=1;j<=3;++j)
                {
                    if(!g[j][i] && !g[j+1][i])
                    {
                        g[j][i] = g[j+1][i] = 1;
                        cout << j << " " << i << endl;
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
            boom();
        }
    }
}