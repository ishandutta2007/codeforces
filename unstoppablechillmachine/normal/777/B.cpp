#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define itn int
#define fro for
#define f first
#define sec second

int n,m,sum,kol,a[5],k,j,j11,sum1;
vector<char> Vec,Vec1;
set<int> st;
string s,s1,s2;
bool t,t1;
char ch;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;

    fro (int i=0;i<n;i++)
    {
        cin>>ch;
        Vec.push_back(ch);
    }

    fro (int i=0;i<n;i++)
    {
        cin>>ch;
        Vec1.push_back(ch);
    }

    sort(Vec.begin(),Vec.end());
    sort(Vec1.begin(),Vec1.end());

    while (j<Vec1.size())
    {
        if (Vec1[j]>=Vec[j11])
        {
            sum++;
            j11++;
        }
        j++;
    }

    j=0;
    j11=0;

    while (j<Vec1.size())
    {
        if (Vec1[j]>Vec[j11])
        {
            sum1++;
            j11++;
        }
        j++;
    }


    cout<<n-sum<<endl<<sum1;
    return 0;
}