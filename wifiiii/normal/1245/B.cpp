#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int aa=0,bb=0,cc=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == 'R') aa++;
            else if(s[i] == 'P') bb++;
            else cc++;
        }
        // a > c, b > a, c > b
        int win=0;
        win += min(c, bb) + min(b, aa) + min(a, cc);
        if(win >= (n+1)/2)
        {
            cout<<"YES"<<endl;
            string t(s.size(),'0');
            for(int i=0;i<s.size();++i)
            {
                if(s[i] == 'R')
                {
                    if(b)
                    {
                        b--;
                        t[i]='P';
                    }
                }
                else if(s[i] == 'P')
                {
                    if(c)
                    {
                        c--;
                        t[i]='S';
                    }
                }
                else
                {
                    if(a)
                    {
                        a--;
                        t[i]='R';
                    }
                }
            }
            for(int i=0;i<s.size();++i)
            {
                if(t[i] == '0')
                {
                    if(a)
                    {
                        a--;
                        t[i]='R';
                    }
                    else if(b)
                    {
                        b--;
                        t[i]='P';
                    }
                    else if(c)
                    {
                        c--;
                        t[i]='S';
                    }
                }
            }
            cout << t << endl;
        }
        else cout<<"NO"<<endl;
    }
}