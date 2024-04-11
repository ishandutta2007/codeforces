#include<bits/stdc++.h>
#define ll long long

//#define __int128 long long

using namespace std;

const int N = 1000+1;

ll ppow(__int128 x,ll y,ll mod)
{
    __int128 res=1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}

ll ppow(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
            res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}

vector<ll> pr;

bool prime(ll x)
{
    for(ll p:pr)
        if(p*p>x)
            return true;
        else if(x%p==0)
            return false;
    for(ll _=0;_<100;_++)
    {
        ll a=rand()+1;
        if(ppow(a,x-1,x)!=1)
            return false;
    }
    return true;
}

ll check(ll x)
{
    for(ll i=1;i<=60;i++)
    {
        ll res=pow((long double)x,1/(long double)i);
        while(ppow(res,i)<x)
            res++;
        while(ppow(res,i)>x)
            res--;
        if(ppow(res,i)==x&&prime(res))
            return res;
    }
    return -1;
}

const ll CBRT=1e6+100;

ll lp[CBRT+1];

void init()
{
    for(ll i=2;i<=CBRT;i++)
    {
        if(lp[i]==0)
            lp[i]=i,pr.push_back(i);
        for(ll p:pr)
        {
            if(p>lp[i]||p*i>CBRT)
                break;
            lp[p*i]=p;
        }
    }
}

int n, k;
ll x[N];

bool cmp(const pair<vector<ll>, ll>& a, const pair<vector<ll>, ll>& b){
    return a.first.size() < b.first.size();
}

void fail(){
    cout << "0\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    init();
    cin >> n >> k;
    if(k==1)
        fail();
    set<ll> primes;
    map<ll, vector<ll>> mp;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        ll p = check(x[i]);
        if(p != -1){
            primes.insert(p);
            mp[p].push_back(x[i]);
        }
    }
    int cnt_primes = 0;
    bool only_pairs = true;
    for(auto el : mp){
        if(el.second.size() == 1){
            primes.erase(el.first);
            continue;
        }
        if(el.second.size() > 2)
            only_pairs = false;
        cnt_primes += el.second.size();
    }
    vector<pair<vector<ll>, ll>> other;
    for(int i = 0; i < n; ++i){
        vector<ll> d;
        ll num = x[i];
        for(ll p : primes)
            if(x[i] % p == 0){
                d.push_back(p);
                do x[i] /= p; while(x[i] % p == 0);
            }
        if(x[i] == 1 && d.size() > 1)
            other.emplace_back(d, num);
    }
    sort(other.begin(), other.end(), cmp);
    vector<ll> ans;
    if(cnt_primes < k){
        if(cnt_primes + other.size() < k)
            fail();
        for(ll p : primes)
            for(ll el : mp[p])
                ans.push_back(el);
        for(int i = 0; ans.size() < k; ++i)
            ans.push_back(other[i].second);
    }
    else if(only_pairs && k%2 == 1){
        if(other.empty() || 2*other[0].first.size() + 1 > k)
            fail();
        set<ll> used;
        ans.push_back(other[0].second);
        for(ll p : other[0].first){
            used.insert(p);
            ans.push_back(mp[p][0]);
            ans.push_back(mp[p][1]);
        }
        for(ll p : primes){
            if(ans.size() == k)
                break;
            if(used.find(p) != used.end())
                continue;
            ans.push_back(mp[p][0]);
            ans.push_back(mp[p][1]);
        }
    }
    else{
        for(ll p : primes){
            if(mp[p].size() == 2 && k-ans.size() == 2){
                ans.push_back(mp[p][0]);
                ans.push_back(mp[p][1]);
                continue;
            }
            if(k-ans.size() <= 3)
                break;
            if(mp[p].size() == 2){
                ans.push_back(mp[p][0]);
                ans.push_back(mp[p][1]);
            }
        }
        for(ll p : primes){
            if(mp[p].size() == 2)
                continue;
            if(k-ans.size() <= mp[p].size()){
                for(ll el : mp[p])
                    if(ans.size() < k)
                        ans.push_back(el);
            }
            else{
                for(ll el : mp[p])
                    if(ans.size() < k-2)
                        ans.push_back(el);
            }
        }
    }
    for(ll el : ans)
        cout << el << " ";
    cout << "\n";
}