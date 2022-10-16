#include<bits/stdc++.h>
using namespace std;
 
bool intersects(int a, int b, int c, int d)
{
    return a <= d && b >= c;
}
 
int main()
{
    int p, q, l, r;
    cin >> p >> q >> l >> r;
 
    vector<pair<int, int> > v1,v2;
 
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        v1.push_back(make_pair(a, b));
    }
 
    for (int i = 0; i < q; i++)
    {
        int c, d;
        cin >> c >> d;
        v2.push_back(make_pair(c, d));
    }
 
    int count = 0;
    for (int k = l; k <= r; k++)
    {
        bool done = false;
        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < p; j++)
            {
               if (intersects(v2[i].first + k, v2[i].second + k, v1[j].first, v1[j].second))
                   done = true;
               if (done)
                   break;
            }
            if (done)
                break;
        }
        if (done)
            count++;
    }
 
    cout << count << endl;
}