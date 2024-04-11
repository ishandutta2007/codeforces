#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;


set < pair < int, int > > S;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (i > 1){
            auto I = S.lower_bound ({x, 0});
            auto it = I;
            it--;
            if (I == S.end())
                cout << (*it).F << " ";
            else if (I == S.begin())
                cout << (*I).F << " ";
            else if ((*I).S < (*it).S)
                cout << (*it).F << " ";
            else
                cout << (*I).F << " ";
        }
        S.insert ({x, i});
    }
    return 0;
}