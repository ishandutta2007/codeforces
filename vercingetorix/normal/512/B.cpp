#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
int n,m;
ll ans;
ll curans;
    int l[301];
int c[301];
int corder[301];
int curp, parts;
std::vector<int> p;
vi praz;
int mini;
int minF[5000];
bool del[301][11];
int part[20];
const long long mod = 1000000007;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

void go(){
    if(curp==praz.size()){
        //vll minF(parts+1, 999999999);
        vi partnum(parts+1, 0);
        int deg2 =1;
            for(int j=0; j<curp; j++) {
                partnum[part[j]]+=deg2;
                deg2*=2;
            }
        ll curcur=0;
        for(int j=1; j<=parts; j++){
            curcur+=minF[partnum[j]];
        }
        if(curcur+curans<ans) {
            ans=curcur+curans;
        }
        return;
    }
    curp++;
    for(int i=1; i<=parts; i++) {
        part[curp-1]=i;
        go();
    }
    parts++;
    part[curp-1]=parts;
    go();
    parts--;
    curp--;
    
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

for(int i=2; i<=100000; i++){
    bool f=false;
    for(int j=0; j<p.size();j++) if(i%p[j]==0){
        f=true;
        break;
    }
    if(f) continue;
    p.push_back(i);
}


    ans=999999999;
    cin>>n;

    for(int i=0; i<n; i++) cin>>l[i];
    for(int i=0; i<n; i++) cin>>c[i];

    vector<pair<int,int>> sr;
    for(int i=0; i<n; i++) sr.pb(mp(c[i],i));
    sort(sr.begin(), sr.end());
    for(int i=0; i<n; i++) corder[i]=sr[i].second;
    int cur=l[0];
    for(int i=1; i<n; i++) {
        cur=gcd(cur, l[i]);
    }
    if(cur>1) {
        cout<<-1;
        return 0;
    }
    for(mini=0; mini<n; mini++) {
        int st = l[mini];
        curans = c[mini];
        praz.clear();
        for(int j=0; j<p.size(); j++) {
            if (st%p[j] == 0) {
                praz.pb(p[j]);
                do {
                    st=st/p[j];
                } while (st % p[j] == 0);
            }
        }
        if(st>1) praz.pb(st);
        int deg2=1;
        for(int j=0; j<praz.size(); j++) {
            int pp=praz[j];
            for(int k=0; k<n; k++) {
                del[k][j] = (l[k]%pp==0);
            }
            deg2*=2;
        }
        for(int k=1; k<deg2; k++) {
            int kk=k;
            vi x;
            for(int j=0; j<praz.size(); j++) {
                if(kk%2==1) x.pb(j);
                kk/=2;
            }
            int num=x.size();
            int minff=99999999;
            for(int i=mini+1; i<n; i++) {
                bool f=true;
                for(int j=0; j<num; j++) {
                    if(del[i][x[j]]){
                        f=false;
                        break;
                    }
                }
                if(f) minff=min(minff, c[i]);
            }
            minF[k]=minff;
        }
        curp=0;
        parts=0;
        go();
    }
    cout<<ans;
    return 0;
}