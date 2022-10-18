#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s[3][3][3];
    #define F(x) for(int x=0;x<3;x++)
    F(i)F(j)F(k)
        cin>>s[i][j][k];
    int x,y;
    cin>>x>>y;
    x=(x-1)%3;
    y=(y-1)%3;
    bool ok=false;
    F(j)F(l)
        if(s[x][j][y][l]=='.')
            s[x][j][y][l]='!',ok=true;
    if(!ok)
        F(i)F(j)F(k)F(l)
            if(s[i][j][k][l]=='.')
                s[i][j][k][l]='!';
    F(i)
    {
        F(j)
        {
            F(k)
                cout<<s[i][j][k]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
}