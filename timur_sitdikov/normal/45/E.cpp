#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

set <string> names[200][2];
int ind[200][2];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, k, num=0;
    string tmp;
    cin >> n;
    for(j=0; j<2; j++)
        for(i=0; i<n; i++)
        {
            cin >> tmp;
            names[tmp[0]][j].insert(tmp);
        }
    for(k='A'; k<='Z'; )
        if (names[k][0].size())
        {
            if (names[k][0].size()>names[k][1].size())
            {
                for(i='A'; i<='Z'; i++)
                    if (names[i][1].size()>names[i][0].size() || i==k && names[i][1].size())
                    {
                        cout << *(names[k][0].begin()) << " " << *(names[i][1].begin());
                        names[k][0].erase(names[k][0].begin());
                        names[i][1].erase(names[i][1].begin());
                        num++;
                        break;
                    }
                if (num<n)
                    cout << ", ";
                continue;
            }
            if (names[k][1].size())
            {
                cout << *(names[k][0].begin()) << " " << *(names[k][1].begin());
                names[k][0].erase(names[k][0].begin());
                names[k][1].erase(names[k][1].begin());
                num++;
            }
            else
            {
                for(i='A'; i<='Z'; i++)
                    if (names[i][1].size()>names[i][0].size())
                    {
                        cout << *(names[k][0].begin()) << " " << *(names[i][1].begin());
                        names[k][0].erase(names[k][0].begin());
                        names[i][1].erase(names[i][1].begin());
                        num++;
                        break;
                    }
            }
            if (num<n)
                cout << ", ";
        }
        else k++;
}