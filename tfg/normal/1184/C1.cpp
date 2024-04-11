#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <assert.h>

using namespace std;

int kolx[515];
int koly[515];

int main()
{
    vector<pair<int,int> > p;
    set<int> x;
    set<int> y;
    int n;
    cin >> n;
    for (int i=0; i<4*n+1; i++)
    {
        int a,b;
        cin >> a >> b;
        x.insert(a);
        ++kolx[a];
        ++koly[b];
        y.insert(b);
        p.push_back({a,b});
    }
    for (auto x1:x)
    {
        if (kolx[x1]<=1)
            continue;
        for (auto x2:x)
        {
            if (x2<=x1)
                continue;
            if (kolx[x2]<=1)
                continue;
            for (auto y1:y)
            {
                if (koly[y1]<=1)
                    continue;
                int y2=y1+(x2-x1);

                if (koly[y2]<=1)
                    continue;

                int kol=0;
                int X,Y;
                for (auto &P:p)
                {
                    if ((P.first==x1||P.first==x2)&&(y1<=P.second)&&P.second<=y2)
                    {
                        ++kol;
                    } else if ((P.second==y1||P.second==y2)&&(x1<=P.first)&&P.first<=x2){
                        ++kol;
                    }
                    else
                    {
                        X=P.first,Y=P.second;
                    }
                }
                //cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << kol << endl;
                if (kol==4*n)
                {
                    cout << X << ' ' << Y << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}