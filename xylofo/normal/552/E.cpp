#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

struct data{
    int indx=-1; //indx to operator to the right
    bool one=1;
    ll pref,suff,ans,without;
    data(){
        pref=suff=ans=without=0;
    }
};

vector<ll> val;
vector<int> mul;

data f(data a, data b) {
    if(a.indx==-1)return b;
    if(b.indx==-1)return a;
    data ans;
    if(mul[a.indx]){
        if(a.one && b.one){
            ans=b;
            ans.pref=ans.suff=(ans.ans*=a.ans);
            return ans;
        } 
        if(a.one){
            ans=b;
            ans.pref=a.ans*b.pref;
            ans.ans=ans.pref+ans.without+ans.suff;
            return ans;
        }
        if(b.one){
            ans=a;
            ans.indx=b.indx;
            ans.suff=b.ans*a.suff;
            ans.ans=ans.pref+ans.without+ans.suff;
            return ans;
        }
        ans.indx=b.indx;
        ans.pref=a.pref;
        ans.suff=b.suff;
        ans.without=a.without+a.suff*b.pref+b.without;
        ans.one=0;
        ans.ans=ans.pref+ans.without+ans.suff;
        return ans;
    }
    else{
        if(a.one && b.one){
            ans.pref=a.ans;
            ans.suff=b.ans;
            ans.ans=ans.pref+ans.suff;
            ans.indx=b.indx;
            ans.one=0;
            return ans;
        }
        if(a.one){
            ans=b;
            ans.without+=b.pref;
            ans.pref=a.ans;
            ans.ans=ans.pref+ans.without+ans.suff;
            return ans;
        }
        if(b.one){
            ans=a;
            ans.indx=b.indx;
            ans.without+=a.suff;
            ans.suff=b.ans;
            ans.ans=ans.pref+ans.without+ans.suff;
            return ans;
        }
        ans.indx=b.indx;
        ans.pref=a.pref;
        ans.suff=b.suff;
        ans.without=a.without+a.suff+b.pref+b.without;
        ans.one=0;
        ans.ans=ans.pref+ans.without+ans.suff;
        return ans;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    s=s+"+";;
    int n=(s.size())/2;
    val.resize(n,0);
    mul.resize(n,0);
    rep(i,0,n){
        val[i]=s[2*i]-'0';
        mul[i]=(s[2*i+1]=='*');
    }
    vector<data> d(n);
    rep(i,0,n){
        d[i].ans=d[i].pref=d[i].suff=val[i];
        d[i].indx=i;
        d[i].without=0;
    }
    ll bst=0;
    vector<data> v(n+1);
    for(int i=n-1;i>=0;--i){
        v[i]=f(d[i],v[i+1]);
    }
    data left;
    rep(i,-1,n){
        if(i>=0)left=f(left,d[i]);
        data midd;
        rep(j,i+1,n){
            midd=f(midd,d[j]);
            data mid=midd;
            mid.pref=mid.suff=mid.ans;
            mid.one=1;
            mid.without=0;
            data right=v[j+1];
            data ans=f(left,f(mid,right));
            bst=max(bst,ans.ans); 
            //cout<<i<<" "<<j<<" "<<ans.ans<<endl;
        }
    }
    cout<<bst<<endl;
    return 0;
}