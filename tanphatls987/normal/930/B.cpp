#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int alp=26;

string s;
int h[alp];
vector <int> v[alp];
int main(){
        cin>>s;
        for(int i=0;i<s.length();i++)
                v[s[i]-'a'].push_back(i);
        int n=s.length();
        int right=0;
        for(int ch=0;ch<alp;ch++) if (!v[ch].empty()){
                int n1=v[ch].size();
                int cans=0;
                for(int gap=1;gap<n;gap++){
                        memset(h,0,sizeof(h));
                        for(auto i:v[ch])
                                h[s[(i+gap)%n]-'a']++;
                        int nans=count(h,h+alp,1);
                        cans=max(cans,nans);    
                }
                right+=cans;
        }
        cout<<setprecision(10)<<(right+.0)/n;
}