#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

bool att[202][202];
int board[52][52];
int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n, m, k;
    scanf("%d\n", &n);
    char c;
    vector<pair<int,int> > fig;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        scanf("%c\n", &c);
        if(c=='o') {
            board[i][j]=0;
            fig.pb(mp(i,j));
        }
        if(c=='x') board[i][j]=1;
        if(c=='.') board[i][j]=-1;
    }
    for(int i=0; i<2*n-1; i++) for(int j=0; j<2*n-1; j++) att[i][j]=true;
    int l=fig.size();
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(board[i][j]==-1) {
            for(int k=0; k<l; k++) {
                att[i-fig[k].first+n-1][j-fig[k].second+n-1] = false;
            }
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(board[i][j]==1) {
            bool flag=false;
            for(int k=0; k<l; k++) {
                if(att[i-fig[k].first+n-1][j-fig[k].second+n-1] == true) {
                    flag=true;
                    break;
                }
            }
            if(!flag) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=0; i<2*n-1; i++) {
    for(int j=0; j<2*n-1; j++) {
        if((i==n-1)&&(j==n-1)) printf("o");
        else if(att[i][j]) printf("x");
        else printf(".");
    }
    printf("\n");
    }

}