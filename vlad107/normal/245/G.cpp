#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <vector>

#define N 500500
#define M 10001

using namespace std;

int ss[N],ff[N],m,ks=0,kol[N],d[M];
map <string,int> ms;
string s1,s2,name[N];
bool g[M][M];
vector< int > u[N];

void add(int x,int y){
        u[x].push_back(y);
        u[y].push_back(x);
}

int main(){
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
        scanf("%d\n",&m);
        ms.clear();
        for (int i=0;i<m;i++){
                cin>>s1>>s2;
                if (!ms[s1]){ks++;ms[s1]=ks;name[ks]=s1;}
                if (!ms[s2]){ks++;ms[s2]=ks;name[ks]=s2;}
                ss[i]=ms[s1];
                ff[i]=ms[s2];
                g[ss[i]][ff[i]]=1;
                g[ff[i]][ss[i]]=1;
        }
        for (int i=0;i<m;i++)
                for (int j=i+1;j<m;j++)
                        if (ss[i]==ss[j])add(ff[i],ff[j]);else
                        if (ss[i]==ff[j])add(ff[i],ss[j]);else
                        if (ff[i]==ss[j])add(ss[i],ff[j]);else
                        if (ff[i]==ff[j])add(ss[i],ss[j]);
        
        for (int i=1;i<=ks;i++){
                for (int j=1;j<=ks;j++)d[j]=0;
                for (int j=0;j<u[i].size();j++)d[u[i][j]]++;
                int mt=0;
                kol[i]=0;
                for (int j=1;j<=ks;j++){        
                        if (g[i][j])continue;
                        if (i==j)continue;
                        if (d[j]>mt){mt=d[j];kol[i]=1;}else
                        if (d[j]==mt)kol[i]++;
                }
        }
        printf("%d\n",ks);
        for (int i=1;i<=ks;i++)cout<<name[i]<<" "<<kol[i]<<endl;
}