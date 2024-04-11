#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
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

class Score{
public:
    Score(int ngs) : gs(ngs), just_won(false) {};
    int s[3];
    int g[3];
    int gs;
    int winner;
    int sets;
    bool just_won;
    void update(int w){
        just_won=false;
        g[w]++;
        if(g[w]==gs){
            s[w]++;
            g[w]=0;
            g[3-w]=0;
            if(s[w]>s[3-w]){
                just_won=true;
                sets=s[w];
                winner=w;
            }
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    vi a;
    int w[3];
    w[1]=0; w[2]=0;
    int g[3][100002];
    int x;
    vvi games(3);
    games[1].pb(0);
    games[2].pb(0);
    for(int i=0; i<n; i++) {
        cin>>x;
        w[x]++;
        a.pb(x);
        games[x].pb(i+1);
        g[1][i+1]=w[1];
        g[2][i+1]=w[2];
    }
    a.pb(0);
    vector<pair<int,int> > ans;
    const int kT=200;
    vector<Score> sc;
    sc.pb(Score(1));
    for(int i=1; i<=kT; i++) sc.pb(Score(i));
    for(int i=0; i<n; i++){
        for(int j=1;j<=kT;j++) sc[j].update(a[i]);
    }
    for(int i=1; i<=kT; i++) if(sc[i].just_won) ans.pb(mp(sc[i].sets, i));
    g[1][0]=0;
    g[2][0]=0;
    for(int t=kT+1; t<=n; t++){
        int set[3];
        set[1]=0;
        set[2]=0;
        int curpos=0;
        while(curpos<n){
            int g1=g[1][curpos];
            int g2=g[2][curpos];
            int newpos=n+1;
            if(g1+t<=w[1]) newpos = games[1][g1+t];
            if((g2+t<=w[2])) newpos = min(newpos,games[2][g2+t]);
            curpos=newpos;
            set[a[curpos-1]]++;
        }
        if((curpos==n)&&(set[a[n-1]]>set[3-a[n-1]])) ans.pb(mp(set[a[n-1]], t));
        
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
    //cout<<ans;
    
}