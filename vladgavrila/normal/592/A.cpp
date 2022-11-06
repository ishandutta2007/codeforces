#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
string s[8];
int ba, bb;

int main()
{
    ba=bb=9;
    for(int i=0; i<8; ++i)
    {
        cin>>s[i];
    }

    for(int i=0; i<8; ++i)
    {
        for(int j=0; j<8; ++j)
        {
            if(s[i][j]=='W')
            {
                int ok=1;
                for(int l=i-1; l>=0; --l)
                {
                    if(s[l][j]!='.')
                        ok=0;
                }
                if(ok)
                    ba=min(ba, i);
            }
            else
            if(s[i][j]=='B')
            {
                int ok=1;
                for(int l=i+1; l<8; ++l)
                {
                    if(s[l][j]!='.')
                        ok=0;
                }
                if(ok)
                    bb=min(bb, 7-i);
            }
        }
    }

    if(ba<=bb)
        cout<<"A\n";
    else
        cout<<"B\n";

    return 0;
}