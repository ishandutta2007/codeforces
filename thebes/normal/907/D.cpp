#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e5+5;
int n, m, i, j, s;
vi arr[MN], a, b, t;

int main(){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m), s=1;
    if(n==1&&m==1) printf("YES\n1\n");
    else if(n==3&&m==3) printf("YES\n6 1 8\n2 9 4\n7 5 3\n");
    else if(m<=3) printf("NO\n");
    else{
        for(i=0;i<n;i++){
            a.clear(); b.clear();
            for(j=0;j<m;j++){
                if(!s){
                    if(j&1) a.pb(i*m+j+1);
                    else b.pb(i*m+j+1);
                }
                else{
                    if(j&1) a.pb(j*n+i+1);
                    else b.pb(j*n+i+1);
                }
            }
            if(m&1){
                if(i&1){
                    for(auto v : a) arr[i].pb(v);
                    for(auto v : b) arr[i].pb(v);
                }
                else{
                    for(auto v : b) arr[i].pb(v);
                    for(auto v : a) arr[i].pb(v);
                }
            }
            else{
                t.clear();
                for(auto v : a) t.pb(v);
                for(auto v : b) t.pb(v);
                if(i&1){for(j=0;j<m;j++) arr[i].pb(t[m-j-1]);}
                else{for(j=0;j<m;j++) arr[i].pb(t[j]);}
            }
        }
        printf("YES\n");
        if(s){
            for(i=0;i<m;i++){
                for(j=0;j<n;j++)
                    printf("%d ",arr[j][i]);
                printf("\n");
            }
        }
        else{
            for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                    printf("%d ",arr[i][j]);
                printf("\n");
            }
        }
    }
}