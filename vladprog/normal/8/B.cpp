#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int x=0,y=0;
    set< pair<int,int> > pos{{0,0}};
    for(char c:s)
    {
        if(c=='U') y++;
        else if(c=='D') y--;
        else if(c=='L') x--;
        else x++;
        if(pos.count({x,y})) cout<<"BUG",exit(0);
        if(pos.count({x,y-1})&&c!='U') cout<<"BUG",exit(0);
        if(pos.count({x,y+1})&&c!='D') cout<<"BUG",exit(0);
        if(pos.count({x+1,y})&&c!='L') cout<<"BUG",exit(0);
        if(pos.count({x-1,y})&&c!='R') cout<<"BUG",exit(0);
        pos.insert({x,y});
    }
    cout<<"OK";
}