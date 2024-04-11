#include <bits/stdc++.h>

using namespace std;
#define int long long
string v="RGB";
int isnt(char x,char y)
{
    if(x!=y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int to1(string s,int m)
{
    int l=0;
    for(int i=0;i<m;++i)
    {
        l+=isnt(s[i],v[(i%3)]);
    }
    return l;
}
int to2(string s,int m)
{
    int l=0;
    for(int i=0;i<m;++i)
    {
        l+=isnt(s[i],v[(i+1)%3]);
    }
    return l;
}
int to3(string s,int m)
{
    int l=0;
    for(int i=0;i<m;++i)
    {
        l+=isnt(s[i],v[(i+2)%3]);
    }
    return l;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n,m;
    string s;
    int x1,x2,x3;
    int y1,y2,y3;
    int h;
    for(int i=0;i<q;++i)
    {
        cin>>n>>m;
        cin>>s;
        x1=to1(s,m); // R
        x2=to2(s,m); // G
        x3=to3(s,m); // B
        h=min(min(x1,x2),x3);
        for(int i=0;i<(n-m);++i)
        {
            y1=x1;
            y2=x2;
            y3=x3;
            y2=x1+isnt(s[i+m],v[(m)%3])-isnt(s[i],'R');
            h=min(h,y2);
            y3=x2+isnt(s[i+m],v[(m+1)%3])-isnt(s[i],'G');
            h=min(h,y3);
            y1=x3+isnt(s[i+m],v[(m+2)%3])-isnt(s[i],'B');
            h=min(h,y1);
            x1=y1;
            x2=y2;
            x3=y3;
        }
        cout<<h<<endl;
    }
    return 0;
}