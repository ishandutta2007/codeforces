#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int a[N][N];
int b[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        string s;
        cin>>s;
        map<char,int> shift;
        shift['i'],shift['j'],shift['k'];
        string ord="ij=k";
        for(char c:s)
            switch(c)
            {
                case 'R': shift[ord[1]]++; break;
                case 'L': shift[ord[1]]--; break;
                case 'D': shift[ord[0]]++; break;
                case 'U': shift[ord[0]]--; break;
                case 'I': swap(ord[1],ord[3]); break;
                case 'C': swap(ord[0],ord[3]); break;
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                map<char,int> val;
                val['i']=i;
                val['j']=j;
                val['k']=a[i][j];
                #define get(ind) (((val[ord[ind]]+shift[ord[ind]])%n+n-1)%n+1)
                b[get(0)][get(1)]=get(3);
            }
        for(int i=1;i<=n;i++,cout<<"\n")
            for(int j=1;j<=n;j++)
                cout<<b[i][j]<<" ";
        cout<<"\n";
    }
}