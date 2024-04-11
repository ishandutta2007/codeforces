#include <iostream>
#include <vector>
#include <string>
using namespace std;
char pole[8][8];
vector <int> mine[8][8];
int din[8][8];
string ans[2];
bool check ( int x, int y, int step )
{
    //cout << x << ' ' << y << '\n';
    if ( x>7||y>7||x<0||y<0 )
        return false;
    else
    {
        for ( int i=0; i<mine[x][y].size(); i++ )
        {
            if ( step==mine[x][y][i]||step==mine[x][y][i]+1 )
                return false;
        }
    }
    return true;
}
bool dfs ( int x, int y, int step )
{
    //cout << x << ' ' << y << '\n';
    if ( mine[x][y].size()==0||mine[x][y][0]<step )
        return true;
    
        bool h=false, f=false;
        if ( check(x-1, y+1, step+1) )
        {
            h=dfs(x-1, y+1, step+1);
        }
        if ( check(x-1, y, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x-1, y, step+1);
        }
        if ( check(x, y+1, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x, y+1, step+1);
        }
        if ( check(x+1, y+1, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x+1, y+1, step+1);
        }
        if ( check(x+1, y-1, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x+1, y-1, step+1);
        }
        if ( check(x-1, y-1, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x-1, y-1, step+1);
        }
        if ( check(x+1, y, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x+1, y, step+1);
        }
        if ( check(x, y-1, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x, y-1, step+1);
        }
        if ( check(x, y, step+1) )
        {
            if ( h )
                f=true;
            h=dfs(x, y, step+1);
        }
        if ( h||f )
            return true;
        return false;
    
}
int main()
{
    ans[0]="LOSE"; ans[1]="WIN";
    for ( int i=0; i<8; i++ )
    {
        string str;
        cin >> str;
        for ( int s=0; s<str.length(); s++ )
            pole[i][s]=str[s];
    }
    for ( int i=0; i<8; i++ )
    {
        for ( int s=0; s<8; s++ )
        {
            if ( pole[i][s]=='S' )
            {
                 int k=0;
                 for ( int q=i; q<8; q++ )
                 {
                     mine[q][s].push_back(k);
                     k++;
                 }    
            }
        }
    }
    cout << ans[dfs(7, 0, 0)];
    return 0;
}

/*

.......A
........
........
.S......
SSS.....
S.S.....
S.S.....
MS......


*/