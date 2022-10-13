#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<int> buckets[n+2];
        for(int i=0;i<n;i++){
            if(a[i]!=-1)
                buckets[a[i]].push_back(i);
        }
        int curr = n;
        int p[n];
        for(int i=0;i<n;i++) p[i] = -1;
        for(int i=n+1;i>=1;i--){
            for(int j : buckets[i]){
                if(i<=n && a[i-1]==-1 && p[i-1]==-1){
                    p[i-1] = curr--;
                } 
                p[j] = curr--;
            }
        }
        for(int i=0;i<n;i++)
            if(p[i]==-1) p[i] = curr--;
        bool work = true;
        vector<int> stack;
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && p[stack[stack.size()-1]]<p[i]){
                stack.pop_back();
            }
            if(stack.empty()){
                if(a[i]!=-1)
                    work = work&&(a[i]==n+1);
                //cout << i<< " " <<n+1 << endl;
            }
            else{
                if(a[i]!=-1)
                    work = work&&(a[i]==stack[stack.size()-1]+1);
                //cout << i << " " << stack[stack.size()-1]+1 << endl;
            }
            stack.push_back(i);
        }
        if(!work){
            cout << -1 << endl;
            continue;
        }
        for(int i=0;i<n;i++)
            cout << p[i] << " ";
        cout << endl;
        
    }
}