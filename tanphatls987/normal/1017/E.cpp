#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef long long ll;
#define X first
#define Y second

const int N=1e5+10;

ii operator -(ii a,ii b){
        return ii(a.X-b.X,a.Y-b.Y);
}
ll operator %(ii a,ii b){
        return 1LL*a.X*b.Y-1LL*a.Y*b.X;
}
ll operator *(ii a,ii b){
        return 1LL*a.X*b.X+1LL*a.Y*b.Y;
}
ll dist(ii a,ii b){
        return (a-b)*(a-b);
}
int CCW(ii a,ii b,ii c){
        ii p1=b-a,p2=c-a;
        if (p1%p2>0) return 1;
        if (p1%p2<0) return -1;
        return 0;
}
ii cpiv;
bool comp(ii a,ii b){
        int type=CCW(cpiv,a,b);
        if (type==0)
                return dist(cpiv,a)<dist(cpiv,b);
        return CCW(cpiv,a,b)==1;
}

struct polygon{
        vector <ii> v;
        vector <ii> ans;
        void add_point(const ii &a){
                v.push_back(a);
        }
        void clear(){
                v.clear();
        }
        void normalize(){
                ans.clear();
                for(auto& i:v) if (i<v.back())
                        swap(i,v.back());
                ans.push_back(v.back());
                v.pop_back();
                cpiv=ans[0];
                

                sort(v.begin(),v.end(),comp);
                for(auto i:v){
                        bool keep=1;
                        while (ans.size()>1){
                                int n=ans.size();
                                int type=CCW(ans[n-2],ans[n-1],i);
                                if (type==1) break;
                                if (type==-1){
                                        ans.pop_back();
                                        continue;
                                }
                                keep=0;
                                if (dist(ans[n-2],i)>dist(ans[n-2],ans[n-1])) ans[n-1]=i;
                                break;
                        }
                        if (keep) ans.push_back(i);
                }
                if (ans.size()>2){
                        int n=ans.size();
                        if (CCW(ans[0],ans[n-1],ans[n-2])==0)
                                ans.pop_back();
                }
        }
        vector <ll> gethash(){
                int n=ans.size();
                vector <ll> samp;
                for(int i=1;i<n-1;i++){
                        samp.push_back(dist(ans[i],ans[i-1]));
                        samp.push_back((ans[i-1]-ans[i])*(ans[i+1]-ans[i]));
                }
                samp.push_back(dist(ans[n-1],ans[n-2]));
                return samp;
        }
}pol[2];
ii a[2][N];


string solve(vector <ll>& a,vector <ll>& b){
        vector <int> tr(a.size(),0);
        for(int i=1;i<a.size();i++){
                tr[i]=tr[i-1];
                while (tr[i]!=0&&a[tr[i]]!=a[i]) tr[i]=tr[tr[i]-1];
                if (a[i]==a[tr[i]]) tr[i]++;
        }
        int len=0;
        for(int i=0;i<b.size();i++){
                ll val=b[i];
                while (len!=0&&a[len]!=val) len=tr[len-1];
                if (a[len]==val) len++;
                if (len==a.size()) 
                        return "YES";
        }
        return "NO";
}
int main(){
        int n1,n2;
        cin>>n1>>n2;
        for(int i=0;i<n1;i++) cin>>a[0][i].X>>a[0][i].Y;
        for(int i=0;i<n2;i++) cin>>a[1][i].X>>a[1][i].Y;
        pol[0].clear();
        pol[1].clear();
        
        for(int i=0;i<n1;i++) pol[0].add_point(a[0][i]);
        for(int i=0;i<n2;i++) pol[1].add_point(a[1][i]);
        pol[0].normalize();
        pol[1].normalize();
        if (pol[0].ans.size()!=pol[1].ans.size()){
                cout<<"NO";
                return 0;
        }
        /*for(int i=0;i<=1;i++){
                cout<<"tick\n";
                for(auto j:pol[i].ans) cout<<j.X<<" "<<j.Y<<'\n';
        }*/
        int nt=pol[0].ans.size();
        for(int i=0;i<nt;i++) pol[0].ans.push_back(pol[0].ans[i]);
        vector <ll> a=pol[0].gethash();
        vector <ll> b=pol[1].gethash();
        cout<<solve(b,a);
}