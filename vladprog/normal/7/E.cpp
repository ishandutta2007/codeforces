#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

signed main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    map<string,int> m; /// 0  -  ?
                       /// 1  -  OK
                       /// 2  -  + or - without ()
                       /// 4  -  * or / without ()
                       /// 6  -  2 and 4
                       /// 8  -  Suspicious
    n++;
    while(n--)
    {
        getline(cin,s);
        s.push_back(' ');
        vector<string> v;
        for(int i=0,p=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(p<i)
                    v.push_back(s.substr(p,i-p));
                p=i+1;
            }
            else if(!(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'))
            {
                if(p<i)
                    v.push_back(s.substr(p,i-p));
                v.push_back(s.substr(i,1));
                p=i+1;
            }
        }
        v.push_back("^");
        int first;
        string name;
        if(v[0]=="#")
            name=v[2],first=3;
        else
            name="need_to_solve",first=0;
        //cout<<name<<":\n";
        for(int i=first,k=0;i<v.size()-1;i++)
        {
            if(v[i]=="(") k++;
            else if(v[i]==")") k--;
            else if(k==0&&(v[i]=="+"||v[i]=="-")) m[name]|=2;
            else if(k==0&&(v[i]=="*"||v[i]=="/")) m[name]|=4;
            else if(v[i][0]>='a'&&v[i][0]<='z'||v[i][0]>='A'&&v[i][0]<='Z'&&m[v[i]])
            {
                if(m[v[i]]==8)
                {
                    m[name]=8;
                    break;
                }
                if((m[v[i]]&2)&&i>first&&(v[i-1]=="*"||v[i-1]=="/"||v[i-1]=="-"))
                {
                    m[name]=8;
                    break;
                }
                if((m[v[i]]&2)&&i<s.size()-1&&(v[i+1]=="*"||v[i+1]=="/"))
                {
                    m[name]=8;
                    break;
                }
                if((m[v[i]]&4)&&i>first&&v[i-1]=="/")
                {
                    m[name]=8;
                    break;
                }
            }
            //cout<<"["<<v[i]<<"] - "<<k<<"\n";
        }
        if(!m[name])
            m[name]=1;
        //cout<<"END\n";
    }
//    for(auto p:m)
//        cout<<p.first<<" -> "<<p.second<<"\n";
    if(m["need_to_solve"]==8)
        cout<<"Suspicious";
    else
        cout<<"OK";
}