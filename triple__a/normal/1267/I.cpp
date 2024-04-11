#include<bits/stdc++.h>
using namespace std;

int n,t,p[2];
int s[107][2];

bool query(int u,int v){
    cout<<"? "<<u<<" "<<v<<endl;
    char s;
    cin>>s;
    return s=='>';
}

void insert(int u,int k){
    int j=++p[k];
    s[j][k]=u;
    while (j>1){
        if (query(s[j-1][k],u)) break;
        swap(s[j-1][k],s[j][k]);
        j--;
    }
}

void erase(){
    if (query(s[p[0]][0],s[p[1]][1])) p[1]--;
    else p[0]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        p[0]=p[1]=0;
        for (int i=1;i<n;++i){
            insert(i,0); insert(i+n,1);
        }
        for (int i=1;i<n-1;++i){
            erase();
        }
        for (int i=n;i<=2*n;i+=n){
            if (p[0]>p[1]){
                insert(i,1);
            }
            else{
                insert(i,0);
            }
            erase();
        }
        cout<<"!"<<endl;
    }
    return 0;
}