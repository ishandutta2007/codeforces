#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, cr, rz;
int v[6];
string pf;
map<string, int> mp;
map<int, string> mpi;
vector<int> p[6];

int main()
{
  //  freopen("b.in", "r", stdin);
   // freopen("b.out", "w", stdout);

    for(int i=0; i<5; ++i)
        cin>>v[i];

    mp["S"]=0; mpi[0]="S";
    mp["M"]=1; mpi[1]="M";
    mp["L"]=2; mpi[2]="L";
    mp["XL"]=3; mpi[3]="XL";
    mp["XXL"]=4; mpi[4]="XXL";

    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            if(0<=i+j && i+j<5)
                p[i].push_back(i+j);
            if(0<=i-j && i-j<5)
                p[i].push_back(i-j);
        }
    }

    cin>>n;
    while(n--)
    {
        cin>>pf;
        cr=mp[pf];
        for(int i=0; i<p[cr].size(); ++i)
        {
            if(v[p[cr][i]]!=0)
            {
                cout<<mpi[p[cr][i]]<<"\n";
                --v[p[cr][i]];
                break;
            }
        }
    }

    return 0;
}