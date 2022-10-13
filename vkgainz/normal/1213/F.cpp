#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[30];
int main(){
    int n,k;
    cin >> n >> k;
    int curr = 0;
    int p1[n];
    int p2[n];
    for(int i=0;i<n;i++) cin >> p1[i];
    for(int i=0;i<n;i++) cin >> p2[i]; 
    for(int i=0;i<n;i++){
        p1[i]--;
        p2[i]--;
    }
    int l = 0;
    int x = 0;
    set<int> temp;
    while(l<n){
        int r = l;
        while(r<n){
            temp.insert(p1[r]);
            temp.insert(p2[r]);
            if(temp.size()==(r-l+1)){
                for(int i=r;i>=l;i--){
                    adj[curr].push_back(p1[i]);
                }
                curr++;
                x++;
                curr = min(curr,25);
                r++;
                temp.clear();
                break;
            }
            else{
                r++;
            }
        }
        l = r;

    }
    if(x<k){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        char ret[n];
        for(int i=0;i<26;i++){
            for(int j : adj[i]){
                ret[j] =i;
            }
        }
        string ref = "abcdefghijklmnopqrstuvwxyz";
        string ans = "";
        for(int i=0;i<n;i++){
            ans+=ref[ret[i]];
        }
        cout << ans << endl;
    }

}