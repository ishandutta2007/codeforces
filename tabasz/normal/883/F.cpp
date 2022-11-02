#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
set<string> S;

string clear(string s)
    {
    string r;
    
    REP(i, s.size())
        {
        r += s[i];
        while((r.size() >= 2 && r[r.size()-2] == 'k' && r.back() == 'h') || 
              (r.size() && r.back() == 'u'))
            {
            if(r.back() == 'u')
                {
                r.pop_back();
                r += 'o';
                r += 'o';
                }
            else
                {
                string u;
                u += r[r.size()-2];
                u += r.back();
                if(u == "kh")
                    {
                    r.pop_back();
                    r.pop_back();
                    r += 'h';
                    }
                else
                    break;
                }
            }     
        }
    return r;
    }
int main()
{
    int n;
    cin>>n;
    REP(i, n)
        {
        string s;
        cin>>s;
        REP(j, 400)
            {
            string s2 = clear(s);
            if(s2 == s)break;
            s = s2;
            }
        S.insert(s);
//        cerr<<s<<" "<<clear(s)<<endl;
        }
    cout<<S.size()<<endl;
}