#include <bits/stdc++.h>

using namespace std;

int n, m, knum, vnum, ing, maxi[3];
int arr[80];
int dyn[80][80][80][3];
int num[80][80][80][3];
char str[80];
vector<int> loc[3];

int f(int k, int v, int a, int x) {
    int i;
    if (k==0&&v==0&&a==0) return 0;
    if (x==0&&k==0||x==1&&v==0||x==2&&a==0) return 987654321;
    if (~dyn[k][v][a][x]) return dyn[k][v][a][x];
    int &res = dyn[k][v][a][x];
    res = 0;
    if (x==0) res = min(f(k-1,v,a,0),f(k-1,v,a,2))+num[k-1][v][a][0];
    if (x==1) res = min(min(f(k,v-1,a,0),f(k,v-1,a,1)),f(k,v-1,a,2))+num[k][v-1][a][1];
    if (x==2) res = min(min(f(k,v,a-1,0),f(k,v,a-1,1)),f(k,v,a-1,2))+num[k][v][a-1][2];
    return res;
}

int main() {
    int i, j, k, v, l;
    scanf("%d",&n);
    scanf("%s",str);
    for (i=0;i<n;i++) {
        if (str[i]=='K') arr[i] = 0;
        else if (str[i]=='V') arr[i] = 1;
        else arr[i]=2;
        maxi[arr[i]]++;
        loc[arr[i]].push_back(i);
    }
    int id[3];
    memset(dyn,-1,sizeof(dyn));
    for (id[0]=0;id[0]<=maxi[0];id[0]++) {
        for (id[1]=0;id[1]<=maxi[1];id[1]++) {
            for (id[2]=0;id[2]<=maxi[2];id[2]++) {
                for (v=0;v<3;v++) {
                    if (id[v]==maxi[v]) continue;
                    int sum = 0;
                    for (l=0;l<3;l++) sum += max(id[l]-(lower_bound(loc[l].begin(),loc[l].end(),loc[v][id[v]])-loc[l].begin()),0);
                    num[id[0]][id[1]][id[2]][v] = loc[v][id[v]]-(id[0]+id[1]+id[2])+sum;
                }
            }
        }
    }
    printf("%d\n",min(min(f(maxi[0],maxi[1],maxi[2],0),f(maxi[0],maxi[1],maxi[2],1)),f(maxi[0],maxi[1],maxi[2],2)));

    return 0;
}