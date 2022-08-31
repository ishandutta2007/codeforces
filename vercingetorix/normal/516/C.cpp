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

int n;
pair<ll, ll> h2md_logl[100000][19];
pair<ll, ll> h2md_logr[100000][19];
ll dist_log[100000][19];
ll h[100000];

int max_2h_minus_d(int from, int to, int dir, ll & dist, ll & alldist) {
    ll curd = 0;
    ll dmark=0;
    ll curtree = from;
    //ll curh2md = 2*h[from];
    int curind = from;
    int l=0;
    if(dir==1) {
        l=to-from;
        if(l<0) l+=n;
    }
    else if(dir==0) {
        l=from-to;
        if(l<0) l+=n;
    }
    l++;
    //l--;
    
    int l2 = 1;
    int deg = 0;
    /*while (l2<=l){
        l2*=2;
        deg++;
    }
    l2--;*/
    while(l>0) {
        if(l%2==1) {
        //if(l>=l2){
            pair<ll,ll> pret;
            if(dir==0) pret = h2md_logl[curtree][deg];
            else pret = h2md_logr[curtree][deg];
            ll dist_bw_marks = 0;
            int newtree = curtree;
            if(dir==1) {
                newtree+=l2;
                if(newtree>=n) newtree-=n;
            }
            else {
                newtree-=l2;
                if(newtree<0) newtree+=n;
            }
            if(dir == 1) dist_bw_marks = dist_log[curtree][deg];
            else {
                dist_bw_marks = dist_log[newtree][deg];
            }
            int pret_ind=pret.first;
            if(pret.second - 2*h[curind] - dmark > 0) {
                //curh2md = pret.second - 2*h[curind] - dmark;
                dmark=dist_bw_marks + pret.second - 2*h[pret_ind];
                curind=pret_ind;
            }
            else {
                dmark+=dist_bw_marks;
            }
            curtree=newtree;
            curd += dist_bw_marks;
            //l-=l2;
        }
        
            l/=2;
            l2*=2;
            deg+=1;
            //deg--;
        
    }
    dist=curd-dmark;
    if(dir==0) alldist = curd - dist_log[curtree][0];
    else {
        curtree--; if (curtree<0) curtree+=n;
        alldist=curd-dist_log[curtree][0];
    }
    return curind;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int m;
  cin>>n>>m;
  for (int i=0; i<n; i++) {
      cin>>dist_log[i][0];
      
  }
  for (int i=0; i<n; i++){
      cin>>h[i];
      h2md_logl[i][0]=mp(i, 2*h[i]);
      h2md_logr[i][0]=mp(i, 2*h[i]);
  }
  int n2=2;
  int deg=1;
  while(n2<2*n){
    int half=n2/2;
    for (int i=0; i<n; i++) {
        int mid=i+half;
        int midl=i-half;
        if(midl<0) midl+=n;
        if(mid>=n) mid-=n;
        ll disttohalf = dist_log[i][deg-1];
        ll disttohalfl = dist_log[midl][deg-1];
        dist_log[i][deg] = disttohalf + dist_log[mid][deg-1];
        if (h2md_logr[i][deg-1].second > h2md_logr[mid][deg-1].second - disttohalf) {
            h2md_logr[i][deg] = h2md_logr[i][deg-1];
        }
        else {
            h2md_logr[i][deg] = mp(h2md_logr[mid][deg-1].first, h2md_logr[mid][deg-1].second - disttohalf);
        }
        if (h2md_logl[i][deg-1].second > h2md_logl[midl][deg-1].second - disttohalfl) {
            h2md_logl[i][deg] = h2md_logl[i][deg-1];
        }
        else {
            h2md_logl[i][deg] = mp(h2md_logl[midl][deg-1].first, h2md_logl[midl][deg-1].second - disttohalfl);
        }
    }
    deg++;
    n2*=2;
  }
//  cout<<ans;
 ll distl, distr, alldist;
  for(int i=0; i<m; i++) {
      int a,b;
      cin >> a >> b;
      int f, t;
        f=b;
        if(f>=n) f-=n;
        t=a-2;
        if(t<0) t+=n;
        int indf=max_2h_minus_d(f,t,1,distl,alldist);
        int indt=max_2h_minus_d(t,f,0,distr,alldist);
        if(indf!=indt){
            cout<<alldist+2*(h[indf]+h[indt])-distl-distr;
        }
        else if(indf==f){
            int newindt=indt+1;
            if(newindt==n) newindt=0;
            ll ndr, nar;
            int indtt=max_2h_minus_d(t,newindt,0,ndr,nar);
            cout << alldist+2*(h[indf]+h[indtt])-distl-ndr;
        }
        else if(indt==t) {
            int newindf=indf-1;
            if(newindf<0) newindf=n-1;
            ll ndl, nal;
            int indff=max_2h_minus_d(f,newindf,1,ndl,nal);
            cout<<alldist+2*(h[indff]+h[indt])-ndl-distr;
        }
        else {
            int newindf=indf-1;
            int newindt=indt+1;
            if(newindf<0) newindf=n-1;
            if(newindt==n) newindt=0;
            ll ndl, ndr;
            ll nal, nar;
            int indff=max_2h_minus_d(f,newindf,1,ndl,nal);
            int indtt=max_2h_minus_d(t,newindt,0,ndr,nar);
            cout<<max(alldist+2*(h[indff]+h[indt])-ndl-distr, alldist+2*(h[indf]+h[indtt])-distl-ndr);
        }
        cout<<endl;

  }
  return 0;
}