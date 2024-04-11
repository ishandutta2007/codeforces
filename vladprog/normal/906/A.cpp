#include <bits/stdc++.h>

#define L //cout<<__LINE__<<endl;

using namespace std;

const int N=1e5;

char t[N];
string w[N];

int main()
{
L   ios_base::sync_with_stdio(0);
L   cin.tie(0);
L   cout.tie(0);
L   int n;
L   cin>>n;
L   for(int i=0;i<n;i++)
        cin>>t[i]>>w[i];
L   char ans=w[n-1][0];
L   set<char> s;
L   for(char t='a';t<='z';t++)
        s.insert(t);
L   int i=0;
L   set<char> can,s2;
L   for(;i<n;i++)
    {
L       switch(t[i])
        {
        case '.':
L           for(char c:w[i])
                s.erase(c);
L           break;
        case '!':
L           can.clear();
L           for(char c:w[i])
                can.insert(c);
            s2=s;
L           for(char c:s)
                if(!can.count(c))
                    s2.erase(c);
            s=s2;
L           break;
        case '?':
L           if(w[i][0]!=ans)
                s.erase(w[i][0]);
            else
                s={w[i][0]};
L           break;
        }
L       if(s.size()==1)
            break;
L   }
L   int k=0;
L   for(i++;i<n;i++)
    {
L       switch(t[i])
        {
        case '!':
L           k++;
L           break;
        case '?':
L           if(w[i][0]!=ans)
                k++;
L           break;
        }
    }
L   cout<<k;
}