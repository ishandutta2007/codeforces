#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second


const int N=2e5+10;
int n,m;
vector <ii> v[N];
ii anss[N];

priority_queue <int> q;             
int main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
                int pos,val;
                cin>>pos>>val;
                v[pos].push_back(ii(val,i));
        }
        int ansc=-1,ansp;

        int sum=0;
        for(int i=n;i>=1;i--){
                for(auto j:v[i]){
                        if (sum+j.X<=m) q.push(j.X),sum+=j.X;
                        else {
                                if (!q.empty()&&j.X<q.top()){
                                        sum+=j.X-q.top();
                                        q.pop();
                                        q.push(j.X);
                                }
                        }
                }
                int cans=min(int(q.size()),i);
                if (cans>ansc)  ansc=cans,ansp=i;
        }
        int n1=0;       
        for(int i=n;i>=ansp;i--)
                for(auto j:v[i]) anss[++n1]=j;
        sort(anss+1,anss+n1+1);
        cout<<ansc<<"\n"<<ansc<<'\n';
        for(int i=1;i<=ansc;i++) cout<<anss[i].Y<<" ";
}