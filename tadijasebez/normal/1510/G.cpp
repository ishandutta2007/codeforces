#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pb push_back
using namespace std;
const int maxn=110;
int n,k;
vector<int>vect[maxn];
int mx[maxn],dep[maxn],rez;

void go(int x){

    mx[x]=0;
    dep[x]=0;
    for(int i=0;i<vect[x].size();i++){

        int id=vect[x][i];

        go(id);

        if(dep[x]<dep[id]){
            dep[x]=dep[id];
            mx[x]=i;
        }
    }
    dep[x]++;

}

void dfs(int x,int restr){

    if(rez==0)return;
    for(int i=0;i<vect[x].size();i++){

        int id=vect[x][i];
        if(i==mx[x] && restr)continue;

        rez--;
        printf("%d ",id);
        dfs(id,0);
        printf("%d ",x);
        if(rez==0)return;
    }

}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)vect[i].clear();

        for(int i=2;i<=n;i++){
            int a;
            scanf("%d",&a);
            vect[a].pb(i);
        }

        go(1);
        if(dep[1]>=k){

            printf("%d\n",k-1);
            printf("1 ");
            int curr=1;
            for(int i=2;i<=k;i++){
                curr=vect[curr][mx[curr]];
                printf("%d ",curr);
            }
            printf("\n");

            continue;
        }


        printf("%d\n",(k-1)*2-dep[1]+1);
        int curr=1;
        rez=k-dep[1];
        while(curr){

            printf("%d ",curr);
            dfs(curr,1);

            if(vect[curr].size()==0)break;
            curr=vect[curr][mx[curr]];
        }
        printf("\n");

    }

return 0;
}