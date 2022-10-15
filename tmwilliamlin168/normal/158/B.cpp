#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int c[4];
    for(int i=0; i<4; ++i)
        c[i]=0;
    while(n--) {
        int a;
        cin >> a;
        ++c[a-1];
    }
    int t=0;
    t+=c[3];
    t+=c[2];
    //cout << t << "\n";
    c[0]-=min(c[0], c[2]);
    t+=c[1]>>1;
    //cout << t << "\n";
    if(c[1]&1) {
        c[0]-=2;
        ++t;
    }
    //cout << t << "\n";
    if(c[0]>0)
        t+=(c[0]-1)/4+1;
    cout << t << "\n";
    return 0;
}