#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ll long long
#define ld long double

int n,m,a,a1,a2,kol;
vector <pair<char,char>> Vec;
set<int> st;
pair <char,char> p;
string s1,s2;
bool t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>s1>>s2;
    for (int i=0;i<s1.size();i++)
    {


            t=false;
            for (int j=0;j<Vec.size();j++)
            {
                if ((s1[i]==Vec[j].first && s2[i]==Vec[j].second) || (s2[i]==Vec[j].first && s1[i]==Vec[j].second)) t=true;
                else if (s1[i]==Vec[j].first || s1[i]==Vec[j].second || s2[i]==Vec[j].first || s2[i]==Vec[j].second)
                {
                    cout<<-1;
                    exit(0);
                }
            }
            if (!t)
            {
                p.first=s1[i];
                p.second=s2[i];
                Vec.push_back(p);
            }

    }

    for (itn i=0;i<Vec.size();i++)
    {
        if (Vec[i].first==Vec[i].second) kol++;
    }

    cout<<Vec.size()-kol<<endl;
    for (int i=0;i<Vec.size();i++)
    {
        if (Vec[i].first!=Vec[i].second) cout<<Vec[i].first<<" "<<Vec[i].second<<endl;
    }


    return 0;
}