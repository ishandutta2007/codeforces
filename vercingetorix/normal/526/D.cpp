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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
   /* std::vector<std::vector<int>> praz(1000001);
    std::vector<bool> isp(1000001,false);
    
    std::vector<int> p;

    
    p.pb(2);
    int i=3;
    praz[2].pb(2);
    int curpi = 0;
    while(i<=1000000){
        int curp=p[curpi];
        while(i<=min(1000000, curp*curp)) {
            bool f=false;
            for(int j=0; j<=curpi; j++) if(i%p[j]==0){
                f=true;
                int x=i/p[j];
                praz[i].push_back(p[j]);
                for(int k=0; k<praz[x].size();k++) praz[i].push_back(praz[x][k]);
                break;
            }
            if(f) {
                i++;
                continue;
                
            }
            p.push_back(i);
            praz[i].pb(i);
            i++;
        }
        curpi++;
    }*/
    
    int n,k;
    //cin>>n>>k;
    scanf("%d %d\n",&n,&k);
    if(k==1) {
        fo(i,0,n) printf("1");
        return 0;
    }
    string s;
    char c;
    fo(i,0,n) {
        scanf("%c", &c);
        s.pb(c);
    }
    vi index(n,-1);
    int ind=0;
    //vector<set<int>> seq(n);
    vvi seq(n);
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    pi[0]=0;
    /*for(int i=0; i<n; i++) {
        if(pi[i]==0) {
            seq[ind].insert(i);
            index[i]=ind;
            ind++;
        }
        else {
            index[i]=index[pi[i]-1];
            seq[index[i]].insert(i);
        }
    }*/
   /* for(int i=n-1;i>=0; i--) {
        if(index[i]>=0) continue;
        int a=i;
        while(a>=0) {
            //seq[ind].insert(a);
            seq[ind].pb(a);
            index[a]=ind;
            a=pi[a]-1;
        }
        reverse(all(seq[ind]));
        ind++;
        }*/
    /*fo(i,0,n) cout<<pi[i]<<" ";cout<<endl;
    fo(i,0,ind) {
        for(auto a=seq[i].begin(); a!=seq[i].end();a++) cout<<*a<<" ";
        cout<<endl;
    }*/
    
    vi ans(n,0);
    vi cc(n+1,0);
    for(int i=1; i<=n/k; i++) {
        int v=k*i-1;
        //int a=*(seq[index[v]].lower_bound((k-1)*i-1));
        //int a = *lower_bound(all(seq[index[v]]), (k-1)*i-1);
        int prev=(k-1)*i;
        int a=v;
        while(a>=prev) {
            int b=pi[a]-1;
            if(b<prev) {
                a=b; continue;
            }
            a=a-((a-prev+1)/(a-b))*(a-b);
        }
        if(a!=(k-1)*i-1) continue;
        ans[v]=1;
        int l=v;
        int r=min(v+i+1,n);
        /*for(int j=v+1; j<min(v+i+1,n); j++) {
            if(s[j]!=s[j-v-1]) break;
            ans[j]=1;
        }*/
        while(r-l>1) {
            int m=(r+l)/2;
            prev=m-i;
            a=m;
            while(a>prev) {
                int b=pi[a]-1;
                if(b<=prev) {
                    a=b; continue;
                }
                a=a-((a-prev)/(a-b))*(a-b);
            }
            if(a==prev) l=m;
            else r=m;
        }
        cc[v]++;
        cc[r]--;
    }
    int cur=0;
    fo(i,0,n) {
        cur+=cc[i];
        if(cur>0) ans[i]=1;
    }
    fo(i,0,n) printf("%d",ans[i]);
    //for(int i=0; i<n; i++)  cout<<pi[i]<<" ";
    //reverse(all(s));
    //fo(i,0,praz[999999].size()) cout<<praz[999999][i]<<" ";
    //cout<<s;
    //for(int i=0; i<n; i++) 
    
}