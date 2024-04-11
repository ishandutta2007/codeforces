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

string st[35][35];
int n, m;

int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, k, i, j, l, a, b, lim;
    string tmp, name;
    cin >> n >> m >> k;
    for(l=0; l<k; l++)
    {
        cin >> tmp;
        if (tmp[0]=='+')
        {
            cin >> a >> b >> name;
            for(i=a; i<=n; i++) 
            {
                if (i==a)
                    lim=b;
                else lim=1;
                for(j=lim; j<=m; j++)
                    if (st[i][j]=="")
                    {
                        st[i][j]=name;
                        goto ll;
                    }
            }
        }
        else
        {
            cin >> name;
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++)
                    if (st[i][j]==name)
                    {
                        cout << i << " " << j << endl;
                        st[i][j]="";
                        goto ll;
                    }
            cout << "-1 -1\n";
        }
ll:     l=l;
    }
    
}