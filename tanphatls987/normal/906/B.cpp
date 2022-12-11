#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;


const int mag[4]={2,0,3,1};
vector <int> v[N];


int n,m;
int f[1<<16];

void showans(){
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                        for(int j=0;j<m;j++) cout<<v[i][j]+1<<" \n"[j==m-1];
}

bool adj(int x,int y){
        if (x>y) swap(x,y);
        if (x%m!=m-1&&y==x+1) return 1;
        if (x/m!=n-1&&y==x+m) return 1;
        return 0;
}
int h[10];
void DP(int x,int y){
        if (y==m){
                DP(x+1,0);
                return;
        }
        if (x==n){
                bool okay=1;
                for(int i=0;i<n;i++)
                        for(int j=0;j<m;j++){
                                if (j<m-1&&adj(v[i][j],v[i][j+1])) okay=0;
                                if (i<n-1&&adj(v[i][j],v[i+1][j])) okay=0;
                        }
                if (okay){
                        showans();
                        exit(0);
                }
                return;
        }
        for(int i=0;i<n*m;i++) if (!h[i]){
                v[x][y]=i;
                h[i]=1;
                DP(x,y+1);
                h[i]=0;
        }
}
int main(){
        cin>>n>>m;
        for(int i=0;i<n;i++) v[i].resize(m);
        if (n>=5){
                for(int j=0;j<m;j++){
                        int cur=0;
                        for(int i=j&1;i<n;i+=2) v[cur++][j]=i*m+j;
                        for(int i=(j&1)^1;i<n;i+=2) v[cur++][j]=i*m+j;
                }
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                        for(int j=0;j<m;j++) cout<<v[i][j]+1<<" \n"[j==m-1];
                return 0;
        }

        if (m>=5){
                for(int i=0;i<n;i++){
                        int cur=0;
                        for(int j=i&1;j<m;j+=2) v[i][cur++]=i*m+j;
                        for(int j=(i&1)^1;j<m;j+=2) v[i][cur++]=i*m+j;
                }
                showans();
                return 0;
        }
        if (n==4){
               for(int j=0;j<m;j++){
                       if (j&1){
                                for(int i=0;i<4;i++) v[i][j]=mag[i]*m+j;
                                continue;
                       }
                       for(int i=3;i>=0;i--) v[3-i][j]=mag[i]*m+j;
               }
               showans();
               return 0;
        }
        if (m==4){
               for(int i=0;i<n;i++){
                       if (i&1){
                                for(int j=0;j<4;j++) v[i][j]=i*m+mag[j];
                                continue;
                       }
                       for(int j=3;j>=0;j--) v[i][3-j]=i*m+mag[j];
               }
               showans();
               return 0;
        }
        DP(0,0);
        cout<<"NO";
}