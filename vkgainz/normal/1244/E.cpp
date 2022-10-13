#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll k;
vector<int> a;
map<int,int> f;
void solve(){
    sort(a.begin(),a.end());
    int min = a[0];
    int max = a[a.size()-1];
    ll numMoves = 0;
    while(numMoves<=k){
        if(min==max){
            break;
        }
        if(f[min]<=f[max]){
            auto it = f.upper_bound(min);
            int nextMin = it->first;
            ll change = (ll) f[min]*(nextMin-min);
            if(numMoves+f[min] > k){
                break;
            }
            else{
                if(numMoves+change<=k){
                    numMoves+=change;

                f[nextMin]+=f[min];
                f[min ] =0;
                min = nextMin;
                }
                else{
                    nextMin = min+((k-numMoves)/f[min]);
                    numMoves+=(ll) f[min]*((k-numMoves)/f[min]);
                    f[nextMin]+=f[min];
                    f[min ] =0;
                    min = nextMin;
                }
            }
        }
        else{
            auto it = f.lower_bound(max);
            it--;
            int nextMax = it->first;
            ll change = (ll) f[max]*(max-nextMax);
            if(numMoves+f[max] > k){
                break;
            }
            else{
                if(numMoves+change<=k){
                    numMoves+=change;

                f[nextMax]+=f[max];
                f[max] = 0;
                max = nextMax;
                }
                else{
                    nextMax = max-((k-numMoves)/f[max]);
                    numMoves+=(ll) f[max]*((k-numMoves)/f[max]);
                    f[nextMax]+=f[max];
                    f[max] = 0;
                    max = nextMax;
                }
            }
        }
    }
    cout << max-min << endl;
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int ai;
        cin >> ai;
        a.push_back(ai);
        f[ai]++;
    }
    solve();
}