#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <list>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
int plog[200001][20];
int llog[200001][20];
int slog[200001][20];
int p[200001];
int l[200001];

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    int ans=0;
    int logpar[100001][20];
    cin>>n;
    std::vector<std::vector<int> > ch(n+1);
    std::vector<int> par(n+1);
    std::vector<std::vector<int> > nb(n+1);
    std::vector<std::vector<int> > lvl(n+1);
    std::vector<int> v_lvl(n+1,0);
    int m=1;
    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v;
        cin >>u>>v;
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    vi subtree(n+1, 1);
    for(int i=l; i>0; i--) for(int j=0; j<lsize[i]; j++) for(int k=0; k<ch[lvl[i][j]].size(); k++) subtree[lvl[i][j]]+=subtree[ch[lvl[i][j]][k]];
    //for(int i=1; i<=n; i++) cout<<subtree[i]<<endl;
    for(int i=1; i<=n; i++) logpar[i][0]=par[i];
    
    int deg=1;
    int p2=2;
    while (p2<n) {
        for(int i=1; i<=n; i++) if (v_lvl[i] > p2) logpar[i][deg] = logpar[logpar[i][deg-1]][deg-1];
        deg++;
        p2*=2;
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int a,b;
        cin>>a>>b;
        if(v_lvl[b]>v_lvl[a]) {
            int sw=b;
            b=a;
            a=sw;
        }
        int stup = v_lvl[a]-v_lvl[b];
        if(stup%2 == 1) {
            cout<<0<<endl;
            continue;
        }
        if(a==b){
            cout<<n<<endl;
            continue;
        }
        deg = 0;
        p2 = 1;
        while(p2 < stup) {
            p2*=2;
            deg++;
        }
        int cura = a;
        while (stup>0) {
            if (stup >= p2) {
                cura = logpar[cura][deg];
                stup-=p2;
            }
            p2/=2;
            deg--;
        }
        int compar;
        int samea=cura;
        int curb=b;
        if (cura==b) compar = b;
        else {
            deg = 0;
            p2 = 1;
            while(p2 < v_lvl[b]) {
                p2*=2;
                deg++;
            }
            while(deg>=0) {
                if((v_lvl[curb]>p2) && (logpar[cura][deg] != logpar[curb][deg])) {
                    cura=logpar[cura][deg];
                    curb=logpar[curb][deg];
                }
                deg--;
                p2/=2;
            }
            compar = par[cura];
        }
        
        if(v_lvl[a]==v_lvl[b]) {
            cout<< n-subtree[cura]-subtree[curb]<<endl;
            continue;
        }
        //cout<<"a "<<v_lvl[a]<<"  b "<<v_lvl[b] << "   compar  " << compar << " its lv  "<<v_lvl[compar]<<endl;
        int tillmid = (v_lvl[b] + v_lvl[a]) / 2 - v_lvl[compar];
        //cout<<tillmid<< " from  " << a<<endl;
        tillmid--;
        cura=a;
        deg = 0;
        p2 = 1;
        while(p2 < tillmid) {
            p2*=2;
            deg++;
        }
        while (tillmid>0) {
            if (tillmid >= p2) {
                cura = logpar[cura][deg];
                tillmid-=p2;
            }
            p2/=2;
            deg--;
        }
        int mid=par[cura];
       //cout<<" mid "<< mid<< " prev  "<<cura<<endl;
        cout<<subtree[mid] - subtree[cura]<<endl;
    }
    
}