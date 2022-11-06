#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int n,m1,m2,t;
    scanf("%d%d%d%d",&n,&m1,&m2,&t);
    int x0[1000001]={0};
    int x1[1000001]={0};
    for (int i=0;i<m1;i++) scanf("%d",&x0[i]);
    for (int i=0;i<m2;i++) scanf("%d",&x1[i]);
    map<int,int> obs;
    for (int i=0;i<m1;i++){obs[-x0[i]]=1;}
    for (int i=0;i<m2;i++){
        if (obs.find(-x1[i])==obs.end()){
            obs[-x1[i]]=2;
        }
        else{
            obs[-x1[i]]+=2;
        }
    }
    obs[0]=0;
    int lobs=n;
    vector<int> toadd(0);
    for (auto i:obs){
        int j=-i.first;
        if (j<lobs-1) {toadd.push_back(j+1);}
        lobs=j;
    }
    for (auto i:toadd){
        obs[-i]=0;
    }
    //On va stocker pour chaque etat en partant de la fin:
    //La date du plus tardif shoot possible
    //Le move potentiel (rien 0, shoot 1  ou change 2 )
    int shotsfired[4000008]={0}; // contain the number of the cell that must be shot to pass this cell
    int bestmove[4000008]={0};
    int nobs=obs.size()*2;
    int cba=n+t;
    int cbb=n+t;
    for (auto i:obs){
        nobs-=2;
        int j=-i.first;
        int typ=i.second;
        if (typ==0){
            
            if(cba!=cbb and max(cba,cbb)>=j){
                if (cba<cbb) {
                    cba=cbb;
                    bestmove[nobs]=2;
                    }
                else{
                    cbb=cba;
                    bestmove[nobs+1]=2;
                }
            }
        }
        if (typ==3){
                shotsfired[nobs]=min(j-1,cba-t);
                cba=shotsfired[nobs];
                shotsfired[nobs+1]=min(j-1,cbb-t);
                cbb=shotsfired[nobs+1];
        }
        if (typ==1){
            if (cbb>max(j-1,cba)) {bestmove[nobs]=2; cba=cbb;}
            shotsfired[nobs]=min(j-1,cba-t);
            cba=shotsfired[nobs];
        }
        if (typ==2){
            if (cba>max(j-1,cbb)) {bestmove[nobs+1]=2; cbb=cba;}
            shotsfired[nobs+1]=min(j-1,cbb-t);
            cbb=shotsfired[nobs+1];
        }
       /*cout<<"  "<<j<<" "<<typ<<"\n";
        cout<<shotsfired[nobs]<<" "<<shotsfired[nobs+1]<<"\n";
        cout<<bestmove[nobs]<<" "<<bestmove[nobs+1]<<"\n";
        cout<<cba<<" "<<cbb<<"\n";*/
        
    }
    if (cba>=t){
        printf("Yes\n");
        set<int> moves;
        map<int,int> shots;
        int curspot=0;
        int i=0;
        for (auto it=obs.rbegin();it!=obs.rend();it++){
                if (bestmove[2*i+curspot]==2){
                    if (shotsfired[2*i+curspot]>0)
                    {shots[shotsfired[2*i+curspot]]=curspot+1;}
                    moves.insert(-it->first);
                    curspot=1-curspot;
                }
                if (shotsfired[2*i+curspot]>0)
                {shots[shotsfired[2*i+curspot]]=curspot+1;}
                i++;
            }
        printf("%d\n",moves.size());
        for (auto j: moves)
            {printf("%d%c",j,(j!=(*moves.rbegin()))?' ':'\n');}
        printf("%d\n",shots.size());
        for (auto i:shots){
            printf("%d %d\n",i.first,i.second);
        }
    }
    else{printf("No\n");}
}