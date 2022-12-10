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
bool used[20][20];
char c;
string hor, vert;
int n,m, wave[400], wsi(0);

void move(int x, int y){
    if(vert[x]=='v' && y<n-1 && !used[x][y+1]){
        used[x][y+1]=1;
        wave[wsi]=x*n+y+1;
        ++wsi;
    }
    else if(vert[x]=='^' && y>0 && !used[x][y-1]){
        used[x][y-1]=1;
        wave[wsi]=x*n+y-1;
        ++wsi;
    }
    if(hor[y]=='>' && x<m-1 && !used[x+1][y]){
        used[x+1][y]=1;
        wave[wsi]=n*(x+1)+y;
        ++wsi;
    }
    else if(hor[y]=='<' && x>0 && !used[x-1][y]){
        used[x-1][y]=1;
        wave[wsi]=n*(x-1)+y;
        ++wsi;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    cin>>hor>>vert;/*
    vert="";
    for(int i(0);i<m;++i){
        cin>>c;
        vert+=c;
    }*/
    for(int i1(0);i1<m;++i1)
        for(int j1(0);j1<n;++j1){
            for(int i(0);i<m;++i)
                for(int j(0);j<n;++j)
                    used[i][j]=0;
            used[i1][j1]=1;
            wsi=1;
            wave[0]=i1*n+j1;
            for(int i(0);i<wsi;++i)
                move(wave[i]/n, wave[i]%n);
            if(wsi!=n*m){
                cout<<"NO";
                return 0;
            }
        };
    cout<<"YES";
    return 0;
}