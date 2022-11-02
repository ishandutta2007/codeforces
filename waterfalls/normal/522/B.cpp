#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair <int, int>
#define PIII pair <PII, int>
main()
{
    int a; cin >> a;
    vector <PII> b;
    int sume=0; 
    int max1=0, max2=0; 
    for (int g=0; g<a; g++)
    {
        int c,d; cin >> c >> d;
        sume+=c; 
        if (d>max1)
        {
            max2=max1; 
            max1=d; 
        }
        else if (d>max2)
        {
            max2=d; 
        }
        b.push_back(PII(c,d)); 
    }
    for (int y=0; y<b.size(); y++)
    {
        int totsum=(sume-b[y].first)*((b[y].second==max1)?(max2):(max1)); 
        cout << totsum << ' '; 
    }
}