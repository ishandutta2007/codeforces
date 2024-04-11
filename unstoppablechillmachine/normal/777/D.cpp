#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define itn int
#define fro for
#define f first
#define sec second

vector<vector<char> > Vec;
int n,sum,j;
string s;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    Vec.resize(n);

    for (int i=0;i<n;i++)
    {
        cin>>s;
        Vec[i].resize(s.size());
        for (int j=0;j<s.size();j++)
        {
            Vec[i][j]=s[j];
        }
    }

    reverse(Vec.begin(),Vec.end());

    for (int i=0;i<n-1;i++)
    {
        j=0;
        while (j<Vec[i].size() && j<Vec[i+1].size() && Vec[i][j]==Vec[i+1][j]) j++;
        if (j>=Vec[i].size())
        {
            Vec[i+1].resize(Vec[i].size());
        }
        if (j>=Vec[i+1].size())
        {
            continue;
        }

        if (Vec[i][j]>Vec[i+1][j])
        {
            continue;
        }
        Vec[i+1].resize(j);
    }

    for (int i=n-1;i>=0;i--)
    {
        for (int j=0;j<Vec[i].size();j++) printf("%c",Vec[i][j]);
        printf("%c",'\n');
    }
    return 0;
}