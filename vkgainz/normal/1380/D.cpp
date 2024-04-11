#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
ll x,k,y;
vector<int> pos;
int a[200001];
int b[200001];
bool work = true;
ll totCost = 0;
void add(int r,int s){
    int lar = 0;
    for(int i=r+1;i<s;i++){
        lar = max(lar,a[i-1]);
    }
    ll add = 10000000000000000;
    if(s-r-1 >=k){
        if(lar<a[r-1] || lar<a[s-1]){
            add = min(add,y*(s-r-1));
        }
        add = min(add,x+y*(s-r-1-k));
        add = min(add,x*((s-r-1)/k)+y*((s-r-1)%k));
    }
    else{
        if(lar<a[r-1] || lar<a[s-1]){
            add = min(add,y*(s-r-1));
        }
        else{
            work = false;
            
        }
    }
    totCost+=add;
}
void solve(){
    int j = 0;
    pos.push_back(0);
    for(int i=0;i<n;i++){
        if(a[i]==b[j]){
            pos.push_back(i+1);
            j++;
        }

    }
    pos.push_back(n+1);
    if(j<m){
        work = false;
        cout << -1 << endl;
        return;
    }
    int l = 0;
    int r = 1;
    while(r<m+2){
        add(pos[l],pos[r]);
        r++;
        l++;
        if(!work){
            break;
        }
    }
    if(!work){
        cout << -1 << endl;
    }
    else{
        cout << totCost << endl;
    }
    
}

int main(){
    cin >> n >> m;
    cin >> x >> k >> y;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    solve();
}