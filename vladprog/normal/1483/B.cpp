#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

template<class It>
It prev(It it,It begin,It end)
{
    if(it==begin)
        it=end;
    it--;
    return it;
}

template<class It>
It next(It it,It begin,It end)
{
    it++;
    if(it==end)
        it=begin;
    return it;
}

ostream&operator<<(ostream&out,list<pii>::iterator it)
{
    return out<<"&("<<it->x<<","<<it->y<<")";
}

ostream&operator<<(ostream&out,list<list<pii>::iterator>::iterator it)
{
    return out<<"&&("<<(*it)->x<<","<<(*it)->y<<")";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        list<pii> a(n);
        list<list<pii>::iterator> p(n);
        for(auto[i,a_it,p_it]=tuple(1,a.begin(),p.begin());a_it!=a.end();i++,a_it++,p_it++)
            a_it->x=i,
            cin>>a_it->y,
            *p_it=a_it;
//        for(auto a_it:p)
//            cerr<<a_it->x<<" "<<a_it->y<<"\n";
        vector<int> ans;
        for(auto[p_it,check]=pair(p.begin(),false);!a.empty()&&!p.empty();)
        {
//            cerr<<"a.size() = "<<a.size()<<"\n";
//            cerr<<"p.size() = "<<p.size()<<"\n";
//            cerr<<"p_it = "<<p_it<<"\n";
            auto&a_it=*p_it;
//            cerr<<"a_it = "<<a_it<<"\n";
            auto a_nit=next(a_it,a.begin(),a.end());
//            cerr<<"a_nit = "<<a_nit<<"\n";
            auto p_nit=next(p_it,p.begin(),p.end());
//            cerr<<"p_nit = "<<p_nit<<"\n";
            if(check)
                if(__gcd(a_it->y,prev(a_it,a.begin(),a.end())->y)==1)
                {
//                    cerr<<"true true\n";
                    ans.push_back(a_it->x);
//                    cerr<<"ans.push_back "<<a_it->x<<"\n";
//                    cerr<<"a.erase "<<a_it<<"\n";
                    a.erase(a_it);
                    if(p.empty()||a.empty())
                        break;
                    a_it=a_nit;
//                    cerr<<"a_it = "<<a_nit<<"\n";
                    if(*p_it==*p_nit&&p.size()>1)
//                        cerr<<"p.erase "<<p_it<<"\n",
                        p.erase(p_it),
//                        cerr<<"check = false"<<"\n",
                        check=false;
                }
                else
                {
//                    cerr<<"true false\n";
//                    cerr<<"p.erase "<<p_it<<"\n";
                    p.erase(p_it);
                    check=true;
//                    cerr<<"check = true\n";
                }
            else
            {
                check=true;
//                cerr<<"check = true\n";
            }
            if(p.empty()||a.empty())
                break;
            p_it=p_nit;
//            cerr<<"p_it = "<<p_nit<<"\n\n";
        }
        cout<<ans.size()<<" ";
        for(int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}