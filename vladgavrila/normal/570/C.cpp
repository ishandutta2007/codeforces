#include <iostream>

using namespace std;

int n, m, p;
string s;
int intervals;
int points;
char c;

int neighborP(int p)
{
    int sol=0;
    if(p>0)
    {
        if(s[p-1]=='.')
            ++sol;
    }
    if(p+1<n)
    {
        if(s[p+1]=='.')
            ++sol;
    }
    return sol;
}


int main()
{
    cin>>n>>m;
    cin>>s;
    for(int i=0; i<n; ++i)
    {
        if(s[i]=='.')
            ++points;

        if(i>0)
        {
            if(s[i-1]!='.' && s[i]=='.')
                ++intervals;
        }
        else
            if(s[i]=='.')
                ++intervals;
    }

    while(m--)
    {
        cin>>p>>c;
        --p;
        if(c=='.')
        {
            if(s[p]=='.')
            {
                s[p]=c;
                        cout<<points-intervals<<"\n";
                continue;
            }
            ++points;

            if(neighborP(p)==0)
                ++intervals;

            if(neighborP(p)==2)
                --intervals;
        }
        else
        {
            if(s[p]!='.')
            {
                s[p]=c;
                        cout<<points-intervals<<"\n";
                continue;
            }
            --points;

            if(neighborP(p)==0)
                --intervals;

            if(neighborP(p)==2)
                ++intervals;
        }
        cout<<points-intervals<<"\n";
        s[p]=c;
    }

    return 0;
}