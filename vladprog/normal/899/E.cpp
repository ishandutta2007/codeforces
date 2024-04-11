#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L mstr<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ mstr<<#__VA_ARGS__<<"\n"
    #define PRT(x) mstr<<#x<<"="<<x<<"\n"
#else
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
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> pi3;
typedef pair< pii , list<pi3>::iterator > pit;
typedef pair<ll,ll> pll;

#define len first.first
#define ind first.second
#define val second
#define inl second
#define mp3(a,b,c) mp(mp(a,b),c)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    list<pi3>a;
    while(n--)
    {
        int t;
        cin>>t;
        if(a.empty())
            a.push_back(mp3(-1,0,t));
        else
            if(a.back().val==t)
                a.back().len--;
            else
                a.push_back(mp3(-1,a.back().ind+1,t));
    }
    map< pii , list<pi3>::iterator >s;
    for(list<pi3>::iterator i=a.begin();i!=a.end();i++)
        s.insert(mp3(i->len,i->ind,i));
    // for(pit t:s) cout<<t.len<<" "<<t.ind<<" "<<t.inl->val<<"\n";
    // cout<<"\n";
    int ans=0;
    while(!s.empty())
    {
        pit t=*s.begin();
        // cout<<t.len<<" "<<t.ind<<" "<<t.inl->val<<"\n";
        s.erase(s.begin());
        ans++;
        list<pi3>::iterator i=t.inl,l=i,r=i;
        if(i==a.begin())
            a.erase(i);
        else
        {
            l--;
            r++;
            a.erase(i);
            if(r!=a.end()&&l->val==r->val)
            {
                s.erase(mp(l->len,l->ind));
                s.erase(mp(r->len,r->ind));
                l->len+=r->len;
                a.erase(r);
                s.insert(mp3(l->len,l->ind,l));
            }
        }
    }
    cout<<ans;
}