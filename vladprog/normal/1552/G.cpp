
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

int n, k;
vector<int> v[100];
int p[100];

void cry()
{
    cout<<"REJECTED\n", exit(0);
}

void proverochka()
{
//    for (int i=1; i<=n; i++)
//        cout<<p[i]<<" ";
//    cout<<endl;
    for (int i=0; i<k; i++)
    {
        vector<int> vals;
        for (int j : v[i])
            vals.pb(p[j]);
        sort(vals.begin(), vals.end());
        int c = 0;
        for (int j : v[i])
            p[j] = vals[c++];
    }
    for (int i=1; i<=n; i++)
        if (p[i] != i)
            cry();
}

void finalochka()
{
    for (int i=1; i<=n; i++)
        p[i] = i;
    while (clock()*1.0/CLOCKS_PER_SEC < 0.9)
    {
        random_shuffle(p+1, p+n+1);
        proverochka();
    }
}

int ft[100];
vector<int> bft[100];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>n>>k;
    for (int i=0; i<k; i++)
    {
        int c;
        cin>>c;
        v[i].resize(c);
        for (int& j : v[i])
            cin>>j;
    }
    memset(ft, 255, sizeof(ft));
    for (int i=0; i<k; i++)
        for (int j : v[i])
            if (ft[j] == -1)
                ft[j] = i;
    for (int i=1; i<=n; i++)
        if (ft[i] == -1)
        {
            if (n!=1)
                cry();
            else
                cout<<"ACCEPTED\n", exit(0);
        }
    for (int i=1; i<=n; i++)
        bft[ft[i]].pb(i);
    vector<int> perm(k);
    for (int i=0; i<k; i++)
        perm[i] = i;
    while (true)
    {
        int c=1;
        for (int i: perm)
            for (int j : bft[i])
                p[j] = c++;
        proverochka();
//        if (!next_permutation(perm.begin(), perm.end()))
//            break;
        random_shuffle(perm.begin(), perm.end());
        if (clock()*1.0/CLOCKS_PER_SEC > 0.9)
            break;
    }
    //finalochka();
    cout<<"ACCEPTED\n";
}
/*
3 10
2 1 2
2 1 3
2 2 3
2 1 2
2 1 2
2 1 3
2 2 3
2 1 3
2 2 3
1 2

3 9
2 1 2
2 1 3
2 2 3
2 1 2
2 1 2
2 1 3
2 2 3
2 1 3
1 2

8 5
3 1 2 3
3 2 3 4
3 3 4 5
3 4 7 8
8 1 2 3 4 5 6 7 8

*/