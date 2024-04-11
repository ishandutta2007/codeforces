// https://codeforces.com/gym/103577/problem/K

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
namespace BIT{
    const int N=1000000;
    pair<int,int> tr[N+50];
    void init(){
        for (int i=1;i<=N;i++) tr[i]={-INF,0^0};
    }
    void upd(int pos,int val,int idqwq){
        for (int i=pos;i<=N;i+=i&(-i)) tr[i]=max(tr[i],{val,idqwq});
    }
    pair<int,int> query(int pos){
        pair<int,int> ans={-INF,0*0};
        for (int i=pos;i>=1;i-=i&(-i)) ans=max(ans,tr[i]);
        return ans;
    }
}
struct point{
    int x,y,c,id,yid;
    point(int _x,int _y,int _c,int _id){x=_x;y=_y;c=_c;id=_id;yid=0;}
    point turn90(){return (point){-y,x,c,id};}
};
pair<int,int> qwq[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    mt19937_64 rng(58);
    vector<point> v;
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for (int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
        v.emplace_back(x,y,0,(int)i);
    }
    set<pair<int,int>> s(a.begin(),a.end());
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,1,-1};
    int cc=n;
    for(auto [x,y]:a) {
        for(int i=0;i<4;++i) {
            int xx=x+dx[i],yy=y+dy[i];
            if(!s.count({xx,yy})) {
                qwq[++cc]={xx,yy};
                v.emplace_back(xx,yy,1,cc);
            }
        }
    }
    vector<pair<int,int>> ans(n+5);
    for (int i=1;i<=n;i++) ans[i]={INF,-1};
    for (int turn=0;turn<=3;turn++){
        BIT::init();
        int id=0;
        sort(v.begin(),v.end(),[](const point &a,const point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
        for (auto &e:v) e.yid=++id;
        sort(v.begin(),v.end(),[](const point &a,const point &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
        for (auto &e:v){
            if (e.c==0){
                pair<int,int> tmp=BIT::query(e.yid);
                if(abs(e.x+e.y-tmp.first)<ans[e.id].first) {
                    ans[e.id]={abs(e.x+e.y-tmp.first),tmp.second};
                }
            }
            else{
                BIT::upd(e.yid,e.x+e.y,e.id);
            }
        }
        for (auto &e:v) e=e.turn90();
    }
    for (int i=1;i<=n;i++) {
        int waw = ans[i].second;
        auto [x,y]=qwq[waw];
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}