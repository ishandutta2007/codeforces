#include<bits/stdc++.h>
using namespace std;
string a[105];
bool cmp(string a,string b)
{
    if(a.length()>b.length())
    {
        return false;
    }
    if(a.length()<b.length())
    {
        return true;
    }
    return a<b;
}
bool zi(int x)
{
    bool tmp;
    for(int i=0;i<a[x+1].length();i++)
    {
        if(a[x][0]==a[x+1][i])
        {
            tmp=true;
            for(int j=1;j<a[x].length();j++)
            {
                if(a[x][j]!=a[x+1][i+j])
                {
                    tmp=false;
                    break;
                }
            }
            if(tmp==true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<m;i++)
    {
        if(zi(i)==false)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=m;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}