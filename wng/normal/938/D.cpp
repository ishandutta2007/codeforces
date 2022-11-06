#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define make_pair(v,w) {v,w}

int main(){
    int n,m;
    //cin>>n>>m;
    scanf("%d %d",&n,&m);
    map<int,map<int,ll>> t;
    for (int i=0;i<m;i++)
    {
        int u,v;
        ll w;
       // cin>>u>>v>>w;
        scanf("%d %d %lld",&u,&v,&w);
        u--;
        v--;
      //  cout<<u<<" "<<v<<" "<<w<<"\n";
        t[u].insert(make_pair(v,w));
        t[v].insert(make_pair(u,w));
    }
    priority_queue<pair<ll,int>> p;
    ll ta[200001]={0};
    for (int i=0;i<n;i++)
    {
        ll a;
        scanf("%lld",&a);
        ta[i]=a;
        p.push(make_pair(-a,i));
     //   cout<<ta[i]<<" ";
    }
   // cout<<endl;
    int visited[200001]={0};
    while (!p.empty())
    {   
		pair<ll,int> firstp=p.top();
		p.pop();
		int num=firstp.second;
        if (!visited[num])
        {
            ll vtoprop=ta[num];
           // cout<<"doing "<<firstp.first<<" "<<firstp.second<<endl;
            visited[num]=true;
            for (auto it: t[num])
            {
                if (!visited[it.first])
                {
                    ll exta=ta[it.first];
                    ll nv=2*it.second+vtoprop;
                    if (exta>nv)
                    {
                     //   cout<<"it : "<<it.first<<" "<<it.second<<endl;//" ; firstp : "<<firstp->first<<" "<<firstp->second;
                        ta[it.first]=nv;
                       //p.erase(make_pair(exta,it.first));
                        p.push(make_pair(-nv,it.first));
                    }
                } 
            }
        }
        
 /*   for (int i=0;i<n;i++)
    {
        cout<<ta[i]<<" ";
    }
    cout<<endl;*/
    }
    for (int i=0;i<n;i++)
    {
       printf("%lld ", ta[i]);
    }
    printf("\n");
}