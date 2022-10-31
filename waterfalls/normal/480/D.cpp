#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Parcel { int in,out,w,s,v; };
bool comp(Parcel a, Parcel b) { return a.out<b.out; }

int n,S;
vector<Parcel> parcels;
int dp[513][1013];
int best[2013];
vector<pair<int,pair<int,int> > > insides[513];

inline int solve(int which, int holds) {
    if (dp[which][holds]!=-1) return dp[which][holds];
    vector<pair<int,pair<int,int> > >& inside = insides[which];
    inside.clear();
    Parcel cur = parcels[which];
    for (int i=1;i<=n;i++) {
        if (which!=i && cur.in<=parcels[i].in && parcels[i].out<=cur.out && holds>=parcels[i].w) {
            int now = min(holds-parcels[i].w,parcels[i].s);
            inside.push_back(make_pair(parcels[i].out,make_pair(parcels[i].in,solve(i,now))));
        }
    }
    best[cur.in] = cur.v;
    int where = 0;
    for (int i=cur.in+1;i<=cur.out;i++) {
        best[i] = best[i-1];
        while (where<inside.size() && inside[where].first==i) {
            best[i] = max(best[i],inside[where].second.second+best[inside[where].second.first]);
            where+=1;
        }
    }
    return dp[which][holds] = best[cur.out];
}

int main() {
    scanf("%d%d",&n,&S);
    for (int i=0;i<n;i++) {
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        Parcel next;
        next.in = a, next.out = b, next.w = c, next.s = d, next.v = e;
        parcels.push_back(next);
    }
    sort(parcels.begin(),parcels.end(),comp);
    Parcel next;
    next.in = 0, next.out = 2*n, next.w = 0, next.s = S, next.v = 0;
    parcels.insert(parcels.begin(),next);
    for (int i=0;i<=n;i++) for (int j=0;j<=S;j++) dp[i][j] = -1;
    printf("%d\n",solve(0,S));

    return 0;
}