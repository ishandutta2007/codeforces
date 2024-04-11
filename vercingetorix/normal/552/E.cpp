
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

vi a(3000);
vi op(3000);

struct partres {
    ll sum;
    ll mn;
};

partres calcstart(int l, int r, partres start) {
    partres cur = start;
    for(int i=l; i<=r; i++) {
        if(op[i]==0) {
            cur.sum=cur.sum+cur.mn*a[i];
            cur.mn=1;
        }
        else {
            cur.mn*=a[i];
        }
    }
    return cur;
}

partres calc(int l, int r) {
    partres start;
    start.sum=0;
    start.mn=1;
    return calcstart(l, r, start);
}



int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    //cin>>n>>k;
    //for(int i=0; i<n; i++) 
    string s;
    cin>>s;
    int l=(s.length()+1)/2;
    
    fo(i,0,l) a[i]=s[2*i]-'0';
    a[l]=0;
    a[l+1]=0;
    vi mpos;
    fo(i,0,l-1) {
        if(s[2*i+1]=='*') {
            mpos.pb(i);
            op[i]=1;
        }
        else op[i]=0;
    }
    op[l-1]=0;
    op[l]=0;
    pi ans = mp(0,0);
    ll curmax=0;
    mpos.pb(-1);
    mpos.pb(l);
    sort(all(mpos));
    int h=mpos.size();
    //cout<<calc(0,4).sum;
    fo(i,0,h) {
        fo(j,i+1,h) {
            int lll=mpos[i];
            int r=mpos[j];
            partres opa=calc(lll+1,r);
            ll prom = opa.sum;
            if(op[r]==1) prom+=opa.mn;
            partres beg=calc(0, lll);
            beg.mn*=prom;
            ll newans;
            if(r<l) newans=calcstart(r+1, l+1, beg).sum;
            else {
                newans=beg.mn+beg.sum;
            }
            if(newans>curmax) {
                ans=mp(lll,r);
                curmax=newans;
            }
            //cout<<'='<<newans<<endl;
        }
    }
    cout<<curmax;
    /*
    cout<<s.substr(0, (lll+1)*2)<<'(';
    cout<<s.substr((lll+1)*2, (r+1)*2-1-(lll+1)*2)<<')';
    if(r<l) cout<<s.substr((r+1)*2-1, 2*l-(r+1)*2)<<endl;*/
    
}