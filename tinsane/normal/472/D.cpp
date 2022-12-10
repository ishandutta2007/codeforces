#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include<algorithm>
#include <queue>
#include <time.h>
#include<functional>
#include<set>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define STR string
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")
struct edge{
    int p1, p2, wei;
};
struct ver{
    bool used;
    vector<PII> edges;
    int anc, rank;
};
int n, mas[2000][2000], wave[2000], wsi(1), lsi(0);
edge lol[2000000];
ver arr[2000];

int comp(const void* a, const void* b){
    return ((edge*)a)->wei-((edge*)b)->wei;
}

bool base(){
    cin>>n;
    for(int i(0);i<n;++i)
        for(int j(0);j<n;++j)
            cin>>mas[i][j];
    for(int i(0), j(0);i<n;++i,++j){
        arr[i].anc=i;
        arr[i].rank=1;
    }
    for(int i(0);i<n;++i)
        for(int j(i+1);j<n;++j){
            if(!mas[i][j]){
                cout<<"NO";
                return 1;
            };
            lol[lsi].p1=i;
            lol[lsi].p2=j;
            lol[lsi].wei=mas[i][j];
            ++lsi;
        };
    qsort(lol, lsi, sizeof(edge), comp);
    //sort(lol, lol+lsi, ncomp);
    return 0;
}

int find_set(int v){
    return (v==arr[v].anc ? v : arr[v].anc=find_set(arr[v].anc));
}

void unite(int x,int y){
    if(arr[x].rank>arr[y].rank)
        swap(x,y);
    arr[y].rank+=arr[x].rank;
    arr[x].anc=y;
}

int main(){
    ios_base::sync_with_stdio(0);
    if(base())
        return 0;
    for(int i(0);i<lsi;++i){
        int l,r;
        r=find_set(lol[i].p1);
        l=find_set(lol[i].p2);
        if(r!=l){
            unite(r,l);
            arr[lol[i].p1].edges.push_back(make_pair(lol[i].wei, lol[i].p2));
            arr[lol[i].p2].edges.push_back(make_pair(lol[i].wei, lol[i].p1));
        }
    }
    for(int t(0);t<n;++t){
        for(int i(0);i<n;++i)
            arr[i].used=0;
        wsi=1;
        wave[0]=t;
        arr[t].used=1;
        if(mas[t][t]){
            cout<<"NO";
            return 0;
        }
        for(int i(0);i<wsi;++i)
            for(int j(0), st(arr[wave[i]].edges.size());j<st;++j)
                if(!arr[arr[wave[i]].edges[j].second].used){
                    wave[wsi]=arr[wave[i]].edges[j].second;
                    if(mas[t][wave[wsi]]!=mas[t][wave[i]]+arr[wave[i]].edges[j].first){
                        cout<<"NO";
                        return 0;
                    }
                    arr[wave[wsi]].used=1;
                    ++wsi;
                };
    }
    cout<<"YES";
    return 0;
}