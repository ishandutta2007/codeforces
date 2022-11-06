#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


unordered_map<int,set<int>> dc;
int representants[300005]={0};
int groupes[1000000]={0};
int kgroupes=0;

bool arebros(int i, int j) //returns true iff j and i are connected and share all neighbours besides themselves.
{
    if (dc.find(i)==dc.end() or dc[i].find(j)==dc[i].end() or dc[i].size()!=dc[j].size()) return false;
    auto iti=dc[i].begin();
    auto itj=dc[j].begin();
    while (iti!=dc[i].end()){
        if ((*iti)==j) {iti++; continue;}
        if ((*itj)==i) {itj++; continue;}
        if ((*iti)!=(*itj)) return false;
        iti++;itj++;
    }
    return true;
}

vector<int> process(int i,bool caniputtwoends) //returns a valid vector and fills all the representants
//or returns empty vector if no solution
{
    vector<int> res;
    representants[i]=i;
    set<int> indignes;
    vector<int> bros;
    bros.push_back(i);
    if (dc.find(i)==dc.end()) {//No friend :(
            res.push_back(i);
            return res;
        } 
    for (auto ci: dc[i])
    {
        if (not representants[ci])
        {
            bool isdone=false;
            for(auto sb:bros){
                if (arebros(sb,ci)) {representants[ci]=sb;  break;}
            }
            if (not representants[ci]) {bros.push_back(ci);}
            if (bros.size()>3) break;
        }
    }
    if (bros.size()<3)
    {
        if (bros.size()==2)
        {   res=process(bros[1],false);
            if (res.size()==0) {
                return res;
            } 
        } 
        res.push_back(i); 
        return res; //No indigne, we're done
        
    }
    if (caniputtwoends and bros.size()==3)
    {
        vector<int> resa=process(bros[1],false);
        resa.push_back(i);
        if (resa.size()==1) {return res;}
        vector<int> resb=process(bros[2],false);
        if (resb.size()==0) {return res;}
        reverse(resb.begin(),resb.end());
        resa.insert(resa.end(),resb.begin(),resb.end());
        return resa;
        }
    return res;
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        dc[a].insert(b);
        dc[b].insert(a);
        }
  //  cout<<"ok\n";
    set<vector<int>> paths;  
    bool isok=true;  
    for (int i=1; i<=n;i++){
        if (not representants[i]){
            vector<int> np=process(i,true);
         //   for (auto i:np){cout<<i<<" ";}
         //   cout<<"ismypah\n";
            if (np.size()==0) {isok=false;break;}
            paths.insert(np);
        }
    }
 //   cout<<"ok2\n";
    if (isok){
        int res[300005]={0};
        int k=1;
        for (auto p:paths)
        {
            int i=0;
            for (auto v:p)
            {
                res[v]=k+i;
                i++;
            }
            k+=p.size()+2;
        }
        printf("YES\n");
        for (int i=1;i<n+1;i++)
        {
            assert(representants[i]!=0);
            printf("%d%c",res[representants[i]],i==n?'\n':' ');
         }
        }
    else {printf("NO\n");}
}